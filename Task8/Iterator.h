#pragma once
#include <iterator>
#include "Matrix.h"

template<typename T>
class IIterator : public iterator<input_iterator_tag, T>
{
    virtual const T& First() const = 0;
    virtual const T& Next() = 0;
};

template <typename Container>
class Iterator : public IIterator<Container>
{
public:
    using  ValueType = typename Container::ValueType;
    using PointerType =  ValueType*;
    typedef ValueType& ReferenceType;
    
    Iterator(PointerType InPtr);

    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    ReferenceType operator[](const int Index);
    PointerType operator->();
    ReferenceType operator*();
    bool operator==(const Iterator& OtherIterator);
    bool operator!=(const Iterator& OtherIterator);

    virtual const ReferenceType First() const override;
    virtual const ReferenceType Next() override;
private:
    PointerType Ptr;
};
