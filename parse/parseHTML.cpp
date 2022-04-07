#include "parseHTML.hpp"
#include "Text.hpp"
#include <libxml/HTMLparser.h>
#include <libxml2/libxml/tree.h>

const char* _file_name;
ElementNode* _root_node;
htmlDocPtr _doc;
int id = 1;

ElementNode* parseHTML(const char* file_name) {
    ElementNode* root_node;
    _file_name = file_name;
    root_node = read();
    parse(root_node);
    
    _root_node = root_node;
    return root_node;
}

ElementNode* read() {
    const char* enc = "utf-8";
    _doc = htmlReadFile(_file_name, enc, HTML_PARSE_RECOVER);
    htmlNodePtr root = xmlDocGetRootElement(_doc);
    Html* root_node = new Html(root);
    //こういうのが破壊的？
    root_node->set_id(id);
    id++;
    return root_node;
}

//改善するコード
void parse(Node* root_node) {
    for (htmlNodePtr node = root_node->get_node()->children; node != NULL; node = node->next) {
        //imgタグは子供を持たないけどelement。is_no_children_element()みたいなので振り分ける様にする。そもそもis_element()かな
        if(node->children || strcmp((char*)(node->name), "img")==0){
            printf("%s\n",node->name);
            ElementNodeFactory* element_factory = new ElementNodeFactory();
            ElementNode* element = element_factory->createNode(node);
            
            //属性をつけてる。これはsetterなのか、そもそもコンストラクタでやるのか
            for(xmlAttrPtr attr = node->properties; NULL != attr; attr = attr->next)
            {
                xmlChar* value = xmlGetProp(node, attr->name);
                element->add_attribute((char*)(attr->name),(char*)(value));
            }
            
    
            element->set_id(id);
            
            element->set_parent(root_node);
            root_node->add_child(element);
            id++;
            parse(element);
        }
        
        //is_textNodeみたいにできたらいいんだろうな、今のところ次（兄弟がないやつをText）にしている。
        else if(!node->next && root_node->get_children_size() == 0) {
            TextNode* text = new TextNode(node);
                text->set_id(id);
                text->set_parent(root_node);
                root_node->add_child(text);
                id++;
        }
        //elementの中のtextでなければTextNodeではないので、Textインスタンスにする
        else{
            char* content = (char*)(node->content);
            if(!content) {
                continue;
            }
            if(content[0] != '\0'){
                TextNode* text = new TextNode(node);
                xmlNodePtr element_ptr = NULL;
                element_ptr = xmlNewNode(NULL, (xmlChar*)("text"));
                Text* element = new Text(element_ptr);
                element->set_parent(root_node);
                element->set_id(id);
                id++;
                text->set_id(id);
                text->set_parent(element);
                element->add_child(text);
                root_node->add_child(element);
                id++;
            }
            
        }
        
    }
}
