#include<iostream>

int main()
{
        int8_t a=12;
        static_assert(sizeof(int)==2);/*this will fail to make the code run normally replace sizeof(int) with 4 inside static assert

        */
		std::cout<<"Yes"<<std::endl;
        return 0;
}
                         
