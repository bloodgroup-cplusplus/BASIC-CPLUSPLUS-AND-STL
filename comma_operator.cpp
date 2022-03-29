#include<iostream>
int fun()
{
        return 1,2,3;

}
int main()
{
        int v1,v2;
        v1 = 1,2,3;

        std::cout<<v1<<std::endl;

        v2 = (1,2,3);


        std::cout<<v2<<std::endl;

        std::cout<<fun()<<std::endl;
        // comma operator executes from left to right 
        // so we get the last output while printing 
        //
        return 0;
}
