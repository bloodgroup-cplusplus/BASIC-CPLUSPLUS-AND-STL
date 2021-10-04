#include<iostream>

int main()
{
	int number = 7;
	int count = 0;
	
	while(number)
	{
		count + = (number &1);
		number>> = 1;
	}
	
	std::count<<count<<std::endl;
	
	return 0;
}
