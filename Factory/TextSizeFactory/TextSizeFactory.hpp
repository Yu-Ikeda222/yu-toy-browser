#ifndef TextSizeFactory_hpp
#define TextSizeFactory_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "ITextSizeFactory.hpp"

class TextSizeFactory : public ITextSizeFactory {
public:
    TextSizeFactory();
    ~TextSizeFactory();
    int get_text_size(const char* tag);
    static int get_text_size_h1(){return 32;};
    static int get_text_size_h2(){return 24;};
    static int get_text_size_h3(){return 16;};
    static int get_text_size_h4(){return 14;};
    static int get_text_size_h5(){return 12;};
    static int get_text_size_h6(){return 10;};
    static int get_text_size(){return 16;};
    std::map<std::string, int(*)()> _factory = {
        {"h1", get_text_size_h1 },
        {"h2", get_text_size_h2 },
        {"h3", get_text_size_h3 },
        {"h4", get_text_size_h4 },
        {"h5", get_text_size_h5 },
        {"h6", get_text_size_h6 },
    };
};
#endif /* TextSizeFactory_hpp */
