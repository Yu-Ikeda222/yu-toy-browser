#ifndef TextSizeFactory_h
#define TextSizeFactory_h

#include <stdio.h>
#include <map>
#include <string>
#include "ITextSizeFactory.h"

class TextSizeFactory : public ITextSizeFactory {
public:
    TextSizeFactory();
    ~TextSizeFactory();
    int getTextSize(const char* tag);
    static int getTextSizeH1(){return 32;};
    static int getTextSizeH2(){return 24;};
    static int getTextSizeH3(){return 16;};
    static int getTextSizeH4(){return 14;};
    static int getTextSizeH5(){return 12;};
    static int getTextSizeH6(){return 10;};
    static int getTextSize(){return 16;};
    std::map<const std::string, int(*)()> _factory = {
        {"h1", getTextSizeH1 },
        {"h2", getTextSizeH2 },
        {"h3", getTextSizeH3 },
        {"h4", getTextSizeH4 },
        {"h5", getTextSizeH5 },
        {"h6", getTextSizeH6 },
    };
};
#endif /* TextSizeFactory_h */
