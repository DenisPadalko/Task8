#pragma once
#include "Matrix.h"

template <typename T>
class Container
{
public:
    using ValueType = T;
    using CustomIterator = Iterator<T>;

    Container(initializer_list<T> Data);

    void LoadFromFile();
    void LoadFromConsole();
    void QuickSort();
    void UsualSort();

    CustomIterator Begin();
    CustomIterator End();
private:
    vector<T> VectorOfData;
};
