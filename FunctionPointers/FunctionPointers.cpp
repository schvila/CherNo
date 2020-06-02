// Function Pointers in C++
//

#include <iostream>
#include <vector>
void HelloWorld(int a)
{
    std::cout << "Hello World. value: " << a << std::endl;
}
void print_val(int val)
{
    std::cout << "Value: "<< val << std::endl;
}

void for_each(const std::vector<int>& values, void(*func)(int))
{
    for (int v : values)
        func(v);
}

int main()
{
    // NO PARAMS 1st version
    //HelloWorld();
    //auto func = &HelloWorld;
    //void(*func)() = &HelloWorld;

    // not used in c++
    typedef void(*HelloWorldFunction)(int);
    HelloWorldFunction func = HelloWorld;
    func(5);
    func(6);

    std::cout << "------------------\n";
    std::vector<int> values = { 1, 5, 4, 2, 3 };
    //for_each(values, print_val);

    //lambda ver
    for_each(values, [](int val){std::cout << "Value: " << val << std::endl; });
}
