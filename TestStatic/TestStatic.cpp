// TestStatic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Singleton
{
public:
    static  Singleton& Get()
    {
        static Singleton instance;
        return instance;
    }
    void Test(){}
};

void Function()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main()
{
    Singleton::Get().Test();
    //Function();
    //Function();
    //Function();
    //Function();
    //Function();

    std::cin.get();

}
