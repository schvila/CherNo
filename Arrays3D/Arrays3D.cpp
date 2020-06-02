// Multidimensional Arrays in C++
//

#include <iostream>

void array5()
{
    // multiple blocks of memory not efficient
    int** a2d = new int* [5];
    for (int i = 0; i < 5; ++i)
    {
        a2d[i] = new int[5];
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            a2d[i][j] = 2;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        delete[] a2d[i];
    }

    //one block much faster
    int* array = new int[5 * 5];
    for (int i = 0; i < 5*5; ++i)
    {
        array[i] = 10;
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            array[j +i*5] = 10;
        }
    }
    delete[] array;
}

int main()
{
    int** a2d = new int* [50];
    for (int i = 0; i < 50; ++i)
    {
        a2d[i] = new int[50];
    }
    for (int i = 0; i < 50; ++i)
    {
        delete[] a2d[i];
    }

    int*** a3d = new int** [50];
    for (int i = 0; i < 50; ++i)
    {
        a3d[i] = new int* [50];
        for (int j = 0; j < 50; ++j)
        {
            a3d[i][j] = new int[50];
        }
    }
}
