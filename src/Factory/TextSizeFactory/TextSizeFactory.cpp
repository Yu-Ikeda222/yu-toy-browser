#include "TextSizeFactory.h"

TextSizeFactory::TextSizeFactory() {

}

TextSizeFactory::~TextSizeFactory() {

}

int TextSizeFactory::getTextSize(const char *tag) {
    int textSize = 0;
    if (_factory.count(tag) == 0) {
        textSize = getTextSize();
    } else {
        textSize = _factory[tag]();
    }
    return textSize;
}
