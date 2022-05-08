#include "parseHTML.h"

const char *fileName;
htmlDocPtr doc;
int id = 1;

ElementNode *parseHtml(const char *htmlFileName) {
    ElementNode *rootNode;
    fileName = htmlFileName;
    rootNode = read();
    parse(rootNode);
    return rootNode;
}

ElementNode *read() {
    const char *enc = "utf-8";
    doc = htmlReadFile(fileName, enc, HTML_PARSE_RECOVER);
    htmlNodePtr root = xmlDocGetRootElement(doc);
    Html *rootNode = new Html(root);
    //こういうのが破壊的？
    rootNode->setId(id);
    id++;
    return rootNode;
}

//改善するコード
void parse(Node *rootNode) {
    for (htmlNodePtr node = rootNode->getNode()->children; node != NULL; node = node->next) {
        //imgタグは子供を持たないけどelement。is_no_children_element()みたいなので振り分ける様にする。そもそもis_element()かな
        if (node->children || strcmp((char *) (node->name), "img") == 0) {
            ElementNodeFactory *elementFactory = new ElementNodeFactory();
            ElementNode *element = elementFactory->createNode(node);
            //属性をつけてる。これはsetterなのか、そもそもコンストラクタでやるのか
            for (xmlAttrPtr attr = node->properties; NULL != attr; attr = attr->next) {
                xmlChar *value = xmlGetProp(node, attr->name);
                element->addAttribute((char *) (attr->name), (char *) (value));
            }
            element->setId(id);
            element->setParent(rootNode);
            rootNode->addChild(element);
            id++;
            element->setPrev();
            if (Node *prev = element->getPrev()) {
//                printf("prev: %s\n", prev->getNode()->name);
                for (auto child: prev->getChildren()) {
//                    printf("clement: %s \n", element->getNode()->content);
//                    printf("content: %s \n", child->getNode()->content);
                }
            }
            parse(element);
        }

            //gloryでばぐる。spanのなかにimgがあるからこの条件に弾かれてしまう。だからprevがspanタグになってしまって位置がずれている。
            //is_textNodeみたいにできたらいいんだろうな、今のところ次（兄弟がないやつをText）にしている。
        else if (!node->next && rootNode->getChildrenSize() == 0) {
            TextNode *text = new TextNode(node);
            text->setId(id);
            text->setParent(rootNode);
            rootNode->addChild(text);
            id++;
        }
            //elementの中のtextでなければTextNodeではないので、Textインスタンスにする
        else {
            char *content = (char *) (node->content);
            if (!content) {
                continue;
            }
            std::string trimContent = trim(content);
            // ここにかかっている
            if (trimContent.size() > 0) {
//                printf("%s\n", trimContent.c_str());
                TextNode *text = new TextNode(node);
                xmlNodePtr elementPtr = NULL;
                elementPtr = xmlNewNode(NULL, (xmlChar *) ("text"));
                Text *element = new Text(elementPtr);
                element->setParent(rootNode);
                element->setId(id);
                id++;
                text->setId(id);
                text->setParent(element);
                element->addChild(text);
                rootNode->addChild(element);
                id++;
                element->setPrev();
//                printf("%d text: %d\n", element->getId(), text->getId());
//                if (Node *prev = element->getPrev()) {
//                    printf("prev: %s\n", prev->getNode()->name);
//                }
            }

        }

    }
}

std::string trim(const std::string &string, const char *trimCharacterList) {
    std::string result;
    std::string reducedString;
    std::string::size_type left = string.find_first_not_of(trimCharacterList);
    if (left != std::string::npos) {
        std::string::size_type right = string.find_last_not_of(trimCharacterList);
        reducedString = string.substr(left, right - left + 1);
    }

    for (int i = 0; i < reducedString.size(); ++i) {
        if ((!isspace(reducedString[i]) || (isspace(reducedString[i]) && !isspace(reducedString[i + 1]))) &&
            reducedString[i] != '\n') {
            result.push_back(reducedString[i]);
        }
    }
    return result;
}
