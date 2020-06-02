// Optimizing the usage of std::vector in C++
//

#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z)
    : x(x), y(y), z(z)
    {  }

    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied x " << x << " y " << y << " z " << z << std::endl;
    }
};

int main()
{
    std::vector<Vertex> vecs;
    vecs.reserve(3);// first optimize
    // see capcity in debug
    //vecs.push_back({ Vertex(1,2,3) });
    //vecs.push_back({ Vertex(4,5,6) });
    //vecs.push_back({ Vertex(7,8,9) });

    //super no copy constructor, constructed directly in vector
    vecs.emplace_back(1,2,3);
    vecs.emplace_back(4,5,6);
    vecs.emplace_back(7,8,9);

}
