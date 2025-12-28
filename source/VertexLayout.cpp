
#include "VertexLayout.hpp"
#include <string>
#include <iostream>

VertexLayout::VertexLayout(int layoutId, int elementsAmount, unsigned int type, unsigned int offset){
    _layoutId = layoutId;
    _elementsAmount = elementsAmount;
    _type = type;
    _offset = offset;
}

int VertexLayout::GetId(){
    return _layoutId;
}

int VertexLayout::GetElementsAmount(){
    return _elementsAmount;
}

unsigned int VertexLayout::GetType(){
    return _type;
}

unsigned int VertexLayout::GetOffset(){
    return _offset;
}

