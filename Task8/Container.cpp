#include "Container.h"
#include "Loader.h"
#include "Sorter.h"

template <typename T>
Container<T>::Container()
{}


template <typename T>
Container<T>::Container(initializer_list<T> Data)
{
    VectorOfData = Data;
}

template <typename T>
void Container<T>::LoadFromFile()
{
    FileLoader Loader;
    vector<string> DataFromFile;
    try
    {
        DataFromFile = Loader.Load();
    }
    catch (const CannotOpenTheFileException& Ex)
    {
        cout << Ex.GetMessage() << endl;
    }
    for(auto& i : DataFromFile)
    {
        VectorOfData.push_back(i);
    }
}

template <typename T>
void Container<T>::LoadFromConsole()
{
    ConsoleLoader Loader;
    vector<string> DataFromConsole = Loader.Load();
    for(auto& i : DataFromConsole)
    {
        VectorOfData.push_back(DataFromConsole);
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
Iterator<T> Container<T>::Begin()
{
    return CustomIterator(VectorOfData.begin());
}

template <typename T>
Iterator<T> Container<T>::End()
{
    return CustomIterator(VectorOfData.begin() + VectorOfData.size());
}

template <typename T>
Iterator<const T> Container<T>::Begin() const
{
    return ConstCustomIterator(VectorOfData.begin());
}

template <typename T>
Iterator<const T> Container<T>::End() const
{
    return ConstCustomIterator(VectorOfData.begin() + VectorOfData.size());
}

template <typename T>
int Container<T>::operator[](const int Index)
{
    return VectorOfData[Index];
}


template <typename T>
int Container<T>::GetSize()
{
    return VectorOfData.size();
}
