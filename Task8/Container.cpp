#include "Container.h"
#include "Sorter.cpp"

template <typename T>
Container<T>::Container()
{}


template <typename T>
Container<T>::Container(initializer_list<T> Data)
{
    for(auto& i : Data)
    {
        VectorOfData.push_back(i);
    }
}

template <typename T>
void Container<T>::LoadFromFile()
{
    vector<string> DataFromFile;
    try
    {
        FileLoader Loader;
        DataFromFile = Loader.Load();
    }
    catch (const CannotOpenTheFileException& Ex)
    {
        cout << Ex.GetMessage() << endl;
    }
    for(auto& i : DataFromFile)
    {
        T* SomeObject = new T(i.c_str());
        VectorOfData.push_back(*SomeObject);
    }
}

template <typename T>
void Container<T>::LoadFromConsole()
{
    ConsoleLoader Loader;
    vector<string> DataFromConsole = Loader.Load();
    for(auto& i : DataFromConsole)
    {
        T* SomeObject = new T(i.c_str());
        VectorOfData.push_back(*SomeObject);
    }
}

template <typename T>
void Container<T>::QuickSort()
{
    QuickSorter<T> Sorter;
    Sorter.Sort(VectorOfData);
}

template <typename T>
void Container<T>::UsualSort()
{
    UsualSorter<T> Sorter;
    Sorter.Sort(VectorOfData);
}

template <typename T>
Iterator<T>& Container<T>::Begin()
{
    return Iterator<T>(VectorOfData.begin());
}

template <typename T>
Iterator<T>& Container<T>::End()
{
    return Iterator<T>(VectorOfData.begin() + VectorOfData.size());
}

template <typename T>
Iterator<const T>& Container<T>::Begin() const
{
    return Iterator<const T>(VectorOfData.begin());
}

template <typename T>
Iterator<const T>& Container<T>::End() const
{
    return Iterator<const T>(VectorOfData.begin() + VectorOfData.size());
}

template <typename T>
const T& Container<T>::operator[](const int Index)
{
    return VectorOfData[Index];
}


template <typename T>
int Container<T>::GetSize()
{
    return VectorOfData.size();
}
