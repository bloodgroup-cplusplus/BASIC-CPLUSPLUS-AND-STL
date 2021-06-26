#include<iostream>
#include<type_traits>

class Class{};

int main()
{
	std::cout<<std::is_floating_point<Class>::value<<"\n";
	std::cout<<std::is_floating_point<float>::value<<"\n";
	std::cout<<std::is_floating_point<int>::value<<"\n";
	
	return -1;
}

