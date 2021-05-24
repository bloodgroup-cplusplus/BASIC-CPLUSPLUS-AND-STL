* What are functors
 *Benefits of a functor
 * Smart function: capabilities beyond operator()
 * It can remember state
 * It can have its own type
 * two functors can be of differnt type even if they are differnt signatures
 *
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
class X
{
        public:
                X(int i)
                {
                }

                void operator()(std::string str)
                {
                        std::cout<<"Call functor x with parameters "<<str<<std::endl;
                }

        //      operator string() const{return"X";}//type conversion paramers

};

void add2(int i)
{
        std::cout<<i+2<<std::endl;
}


template<int val>
//This value has to be a compile time constant
//we cannot use addVal<at run time value> so using templates is not a good idea as well
void addVal(int i)
{
        std::cout<<val+i<<std::endl;
}

// This is a functor

class AddValue
{
        int val;
        public:
                AddValue(int j):val(j){}
                void operator()(int i)
                {
                        std::cout<<i+val<<std::endl;
                }
};

int main()
{
        X foo(8);
        foo("Hi");// Calling functor X with paramerter Hi
        std::vector<int> vec={1,2,3,4,5};
        std::cout<<"This is a  vector with initial values as {1,2,3,4,5}"<<std::endl;
        std::cout<<"we add 2 to each element using function_call, template and a functor"<<std::endl;
        std::cout<<"Called using a function named add2 this adds 2 to each vec element"<<std::endl;
        std::for_each(vec.begin(),vec.end(),add2);//{4,5,6,7}
        std::cout<<"Called using a function template with 2 initialzed at compiletime"<<std::endl;
        std::for_each(vec.begin(),vec.end(),addVal<2>);
        // so the solution here should be to used so called functors
        int x=2;
        std::cout<<"called using a functor with value to add as 2"<<std::endl;
        std::for_each(vec.begin(),vec.end(),AddValue(x));
        // we add the parameters to call the functors

        return 0;

}
~                                                                                                                                                                                                                                                                                                                                                                             
~                                                                                                                                                                                                                                                                                                                                                                             
~                                                                                                                                                                                                                                                                                                                                                                            
