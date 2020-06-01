// LRvalues.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
// no storage/location R value
int get_value()
{
	return 35;
}
int& get_value_r()
{
	static int v = 50;
	return v;
}

void print_name(const std::string& name)
{
	std::cout << "[Lvalue] "<< name << std::endl;
}

//r value reference, overload
void print_name(std::string&& name)
{
	std::cout << "[Rvalue] " << name << std::endl;
}

int main()
{
	int i{ 10 };
	// i is left, 10 is right: 10 = i je nesmysl.
	i = get_value();
	//get_value() = 51; nesmysl r value.
	get_value_r() = 200;

	//int& a = 30;
	const int& a = 30; //ok, asi vytvori temp pro 30.


	const std::string first_name = "Stan";
	const std::string last_name = "Chvila";

	const std::string full_name = first_name + last_name;
	print_name(full_name);
	print_name(first_name + last_name);

	

	
}

