// The Arrow Operator in C++
//

#include <iostream>
class Entity
{
public:
    void Print(const char* txt) const
    {
        std::cout << "Print " << txt<< std::endl;
    }
};
class ScopedPtr
{
private:
    Entity* m_obj;
public:
    ScopedPtr(Entity* entity )
    : m_obj(entity)
    {
        std::cout << "ScopedPtr ctor\n";
    }
    ~ScopedPtr()
    {
        delete m_obj;
    }
    //Entity* get_object() { return m_obj; }
    Entity* operator->() { return m_obj; }
};
/// Test offset in memory
struct Vector
{
    float x, y, z;
};
int main()
{
    int ofs_x = (int)&((Vector*)nullptr)->x;
    int ofs_y = (int)&((Vector*)nullptr)->y;
    int ofs_z = (int)&((Vector*)nullptr)->z;
    std::cout << ofs_x << "," << ofs_y << "," << ofs_z << std::endl;

    ScopedPtr se = new Entity(); // zajimave
    //se.get_object()->Print("scoped ent");
    se->Print("scoped arrow overloaded");

    //Entity e;
    //e.Print("entity");
    //Entity* p = &e;
    //p->Print("arrow");
    //(*p).Print("ptr cast"); // debilni zapis
    //Entity& ent = e;
    //ent.Print("reference");
}
