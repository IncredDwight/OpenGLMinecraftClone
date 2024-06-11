
#ifndef VertexLayout_hpp
#define VertexLayout_hpp

#include <stdio.h>

struct VertexLayout{
public:
    VertexLayout(int layoutId, int elementsAmount, unsigned int type, unsigned int offset);
    int GetId();
    int GetElementsAmount();
    unsigned int GetType();
    unsigned int GetOffset();
    
private:
    int _layoutId = 0;
    int _elementsAmount = 0;
    unsigned int _type;
    unsigned int _offset;
};

#endif 
