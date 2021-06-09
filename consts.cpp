// const 
//  a compile time constraint that an object can not be modified
#include<iostream>
int main()
{
        const int i=9;
        // this enforces the constness during compile time

        // const cast can refrence away the value of i
        const_cast<int&> (i)=6;
        std::cout<<i<<std::endl;
        const int *p1 =& i; // data is const, pointer is not a constant

        //if we do
        //*p1=5; // this will not compile
        p1++;// this can be changed
        std::cout<<p1<<std::endl;
        // pionter can be changed but pointer data cannot be changed
        //const int (means the integer contained is a const)
        //
//      int *  const p2;
        // this is the opposite of p1
        // p2 is const but the data it points to is not a const
        //
        //const p2 = p2 is a const
//      const int * p3; // data and pointer are both const

        int const *p3 =&i;
        // the rule is that
        // If const is on the left of * , data is const
        // If const is on the right of *, pointer is const
        //
        const int * p4=&i;
        //constness of a data can be casted 
        // let's say we have a j which is not a const and in certain point we want to make j a const
        int j;
        static_cast<const int &> (j);
        // this will make j a const integer;
        // cast is not a good thing cast is not a good way of coding    
        /* a)Guards agains inadvertent write to the variable.
         * b) Self documenting
         * c) Enables compiler to do more optimization, making code tighter
         * d) Const means the variable can be put in ROM
         * e) this is used in c++ programming
         */
        return 0;

}
