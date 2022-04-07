#ifndef ITextSizeFactory_hpp
#define ITextSizeFactory_hpp
#include <stdio.h>

class ITextSizeFactory{
public:
    virtual int get_text_size(const char* tag)=0;
};
#endif /* ITextSizeFactory_hpp */
