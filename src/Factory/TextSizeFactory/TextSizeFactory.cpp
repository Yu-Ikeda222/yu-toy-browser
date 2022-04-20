#include "TextSizeFactory.h"

TextSizeFactory::TextSizeFactory() {

}

TextSizeFactory::~TextSizeFactory() {

}

int TextSizeFactory::getTextSize(const char *tag) {
    int text_size = 0;
    if (_factory.count(tag) == 0) {
        text_size = getTextSize();
    } else {
        text_size = _factory[tag]();
    }
    return text_size;
}
