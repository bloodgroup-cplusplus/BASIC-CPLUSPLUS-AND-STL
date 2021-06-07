#include<iostream>
#include<vector>

constexpr int A()//forces the computation to happen at compile time
{
        return 3;


}

constexpr int cubed(int x)
{
        return x*x*x;
}



int main()
{
        std::vector<int> arr(A()+3);// this creates an array of size 6
        std::cout<<"the size of this vector is"<<arr.size()<<std::endl;
        int y=cubed(1789);//computed at compile time;
        std::cout<<y<<std::endl;
        return 0;
}

~                                                                                              
~                                                                                              
~                 
