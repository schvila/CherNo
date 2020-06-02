// Unions in C++
//

#include <iostream>
struct Vector2
{
    float x, y;
};
struct Vector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        //this will occupy the same space as first union member
        struct
        {
            Vector2 a, b; // a the same memory as x, y. b as z, w.
        };
    };
};
void PrintVector2(const Vector2 vector)
{
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    Vector4 v4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    PrintVector2(v4.a);
    PrintVector2(v4.b);
    v4.z = 500.0f;
    std::cout << "------------------------------------\n";
    PrintVector2(v4.a);
    PrintVector2(v4.b);

}
