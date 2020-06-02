// Type Punning in C++
//

#include <iostream>

struct Entity
{
    int x, y;
    int* get_position()
    {
        return &x;
    }
};
int main()
{
    Entity e = { 5,8 };
    int* ps = (int*)&e;
    std::cout << ps[0] << ", " << ps[1] << std::endl;

    int* position = e.get_position();
    position[1] = 10; //writes y
    std::cout << ps[0] << ", " << ps[1] << std::endl;

    //crazy 
    int y = *(int*)((char*)&e + 4);
    std::cout << "Crazy y: " << y << std::endl;

}
