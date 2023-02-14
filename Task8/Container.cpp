#include "Container.h"

template <typename T>
Container<T>::Container(initializer_list<T> Data)
{
    
}

template <typename T>
typename Container<T>::CustomIterator Container<T>::Begin()
{
    return CustomIterator(VectorOfData.begin());
}

template <typename T>
typename Container<T>::CustomIterator Container<T>::End()
{
    return CustomIterator(VectorOfData.end());
}
