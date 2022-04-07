#ifndef parseHTML_hpp
#define parseHTML_hpp

#include <stdio.h>
#include <libxml/HTMLparser.h>
#include "ElementNode.hpp"
#include "TextNode.hpp"
#include "ElementNodeFactory.hpp"


extern ElementNode* parseHTML(const char* file_name);
extern const char* _file_name;
extern ElementNode* _root_node;
extern htmlDocPtr _doc;
extern ElementNode* read();
extern void parse(Node* root_node);
extern void Trim(char *str);


#endif /* parseHTML_hpp */
