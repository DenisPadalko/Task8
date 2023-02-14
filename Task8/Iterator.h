#pragma once
#include <iterator>
#include "Matrix.h"

template<typename T>
class IIterator : public iterator<input_iterator_tag, T>
{
    virtual const T& First() const = 0;
    virtual const T& Next() = 0;
};

template <typename T>
class Iterator : public IIterator<T>
{
public:
    Iterator(T* InPtr);

    Iterator& operator++();
    Iterator& operator++(int);
    T& operator[](const int Index);
    T* operator->();
    T& operator*();
    bool operator==(const Iterator& OtherIterator);
    bool operator!=(const Iterator& OtherIterator);

    virtual const T& First() const override;
    virtual const T& Next() override;
private:
    T* Ptr;
};
