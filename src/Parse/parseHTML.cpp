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
            parse(element);
        }
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
            if (content[0] != '\0') {
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
            }

        }

    }
}
