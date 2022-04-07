#include "TextSizeFactory.hpp"

TextSizeFactory::TextSizeFactory(){
    
}

TextSizeFactory::~TextSizeFactory(){
    
}

int TextSizeFactory::get_text_size(const char* tag) {
    int text_size = 0;
    if (_factory.count(tag) == 0) {
        text_size = get_text_size();
    } else {
        text_size = _factory[tag]();
    }
    return text_size;
}
