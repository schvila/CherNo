// Track MEMORY ALLOCATIONS the Easy Way in C++
//

#include <iostream>
#include <memory>
struct AllocationMetrics
{
	size_t total_allocated{ 0 };
	size_t total_freed{ 0 };

	size_t CurrentUsage() const { return total_allocated - total_freed; };
};
static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) noexcept
{
	//std::cout << "Allocating " << size << std::endl;
	s_AllocationMetrics.total_allocated += size;
	return malloc(size);
}
void operator delete(void * memory, size_t size) noexcept
{
	//std::cout << "Freeing " << size << std::endl;
	s_AllocationMetrics.total_freed += size;
	free(memory);
}
static void PrintMemoryUsage()
{
	std::cout << "Memory usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}
struct Object
{
	int x, y, z;
};
int main()
{
	PrintMemoryUsage();
	std::string s = "Standa";
	PrintMemoryUsage();
	//Object* obj = new Object;
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

}

