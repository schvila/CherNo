// MoveSemantics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		std::cout <<"Created!\n";
		m_size = strlen(string);
		m_data = new char[m_size];
		memcpy(m_data, string, m_size);
	}
	String(const String& other)
	{
		std::cout << "Copied!\n";
		m_size = other.m_size;
		m_data = new char[m_size];
		memcpy(m_data, other.m_data, m_size);
	}
	String(const String&& other) noexcept
	{
		std::cout << "Moved!\n";
		m_size = other.m_size;
		m_data = other.m_data;
		other.m_size = 0;
		other.m_data = nullptr;
	}
	~String()
	{
		delete m_data;
	}
	void Print()
	{
		for (size_t i = 0; i < m_size; i++)
			std::cout << m_data[i];
		std::cout << std::endl;
	}
private:
	mutable char* m_data;
	mutable size_t m_size;
};

class Entity
{
public:
	Entity(const String& name)
		: m_Name(name)
	{
		
	}
	Entity(const String&& name)
		: m_Name(const_cast<String&&>(name)) // must cst to use move constructor
	{

	}
	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
	Entity entity(String("Cherno"));
	entity.PrintName();
}

