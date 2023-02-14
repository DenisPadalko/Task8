#include "Matrix.h"
#include "Container.h"
#include "Container.cpp"

int main(int argc, char* argv[])
{
    Container<Matrix> SomeDataContainer;
    SomeDataContainer.LoadFromFile();
    SomeDataContainer.LoadFromConsole();
    SomeDataContainer.QuickSort();
    for(int i = 0; i < SomeDataContainer.GetSize(); ++i)
    {
        cout << SomeDataContainer[i] << endl;
    }
    return 0;
}
