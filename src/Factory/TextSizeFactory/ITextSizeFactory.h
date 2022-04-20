#ifndef ITextSizeFactory_h
#define ITextSizeFactory_h
#include <stdio.h>

class ITextSizeFactory{
public:
    virtual int getTextSize(const char* tag)=0;
};
#endif /* ITextSizeFactory_h */
