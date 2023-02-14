#pragma once
#include "Matrix.h"
#include "Iterator.h"

template <typename T>
class Container
{
public:
    Container();
    Container(initializer_list<T> Data);

    void LoadFromFile();
    void LoadFromConsole();
    void QuickSort();
    void UsualSort();

    Iterator<T> Begin();
    Iterator<T> End();
    Iterator<const T> Begin() const;
    Iterator<const T> End() const;

    int operator[](const int Index);
    
    int GetSize();
private:
    vector<T> VectorOfData;
};
