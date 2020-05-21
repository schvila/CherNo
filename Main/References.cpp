// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define LOG(x) std::cout << x << std::endl;

void Increment(int* val)
{
    (*val)++;
}
void Increment(int& val)
{
    val++;
}
int main()
{
    int a = 5;
    //int& ref = a;
    //ref = 10;
    Increment(&a);
    Increment(a);
    LOG(a);
    std::cin.get();
}
