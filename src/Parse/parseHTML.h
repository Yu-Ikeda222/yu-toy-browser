#ifndef YU_TOY_BROWSER_PARSEHTML_h
#define YU_TOY_BROWSER_PARSEHTML_h

#include <stdio.h>
#include <libxml/HTMLparser.h>
#include "../Node/ElementNode.h"
#include "../Node/TextNode.h"
#include "../Node/Elements/Text.h"
#include "../Factory/ElementNodeFactory/ElementNodeFactory.h"
#include <libxml2/libxml/tree.h>

extern ElementNode *parseHtml(const char *htmlFileName);

extern const char *fileName;
extern htmlDocPtr doc;

extern ElementNode *read();

extern void parse(Node *rootNode);


#endif /* YU_TOY_BROWSER_PARSEHTML_h */
