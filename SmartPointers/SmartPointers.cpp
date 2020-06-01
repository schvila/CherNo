// SMART POINTERS in C++ (std::unique_ptr, std::shared_ptr, std::weak_ptr)
//

#include <iostream>
#include <memory>
class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity\n";
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity\n";
    }
};

int main()
{
    {
        std::unique_ptr<Entity> ent = std::make_unique<Entity>();
    }
    std::shared_ptr<Entity> se = std::make_shared<Entity>();
    {
        std::shared_ptr<Entity> se2 = se;
        std::cout << "[se2] icrease counter [se], freed after this scope.\n";
    }
}
