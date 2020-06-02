// Lambdas in C++
//

#include <iostream>
#include<vector>
#include <functional>

//void for_each(const std::vector<int>& values, void(*func)(int))
void for_each(const std::vector<int>& values, const std::function<void(int)>& func)
{
    for (int v : values)
        func(v);
}

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3 };
    auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
    std::cout << *it << std::endl;

    //for_each(values, [](int val) {std::cout << "Value: " << val << std::endl; });
    int a{ 23 };
    auto lambda = [a](int val) {std::cout << "Value: " << val << " a: " << a << std::endl; };
    for_each(values, lambda );
}
