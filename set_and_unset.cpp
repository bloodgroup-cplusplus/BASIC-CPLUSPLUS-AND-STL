// Question: How to set, clear, toggle, check, changing a single bit using C/C++?


#include<iostream>


int main()
{
        int number =3;

        // 0011 (third bit)

        //Set one bit [use of bitwise OR operator]

        int bitPos =2;

        number |= (1<<bitPos);

        std::cout<<number<<std::endl;
        // this will print seven (we are changing the number using bitwise operator)

        // we are doing a left shift on 1 twice 
        // 0001
        // twice leftshit //0100 
        // move the one on with the given positons.
        // It will result in three times one

        // unsetting using & operator 


        int number_two = 3;

        //unset one bit [ use of bitwise operator ]

        int bitpos = 1;

        number_two &= ~(1<<bitPos);

        std::cout<<number_two<<std::endl;

        //0010
        //1101
        //0011
        //0001



        return 0;
}
