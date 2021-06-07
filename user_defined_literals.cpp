/*
 * user defined literals
 * literals are constants
 * c++ has four types of literals
 * integers ==45
 * float =4.5
 * character='a'
 * string= "Dog"
 * 45; // int literal
 * 45u // unsigned int( suffix specifies type)
 * 451;// long
 * and the user defined literals allows us to define our own suffixes
 * so whole thing can be treated as whole type of literal
 *
 * say we are using old c++ and we wan't to define a variable height which is a long double
 * long double height=3.4; what does this mean Meters? Centimeters? Inches?
 * this is one of the thing that makes us write only only the writer of the code  knows what he is doing
 * if you are going to work for long time m is always used for time and khz for frequencies
 * so we waaste lot of our type fumbling around type of variables
 * so we should be restricting around conventions
 *
 *
 * Ideallay we always attach uints to the value;
 * height=3.4cm
 * ratio=3.4.cm/2.1mm // ratio 3.4*10/2.1 (cm/mm) so translation is required
 * so the above is the above  code
 * the unit translation means run-time cost and  long time cost is costly
 * unit translation needs to happen many time then it takes lot of time
 * so we can have a user defined literals
 *the importance of user defined literals push the effort of classes and structs
 * user defined literals only works with following parameters
 * char const *
 * unsigned long long
 * long double
 * char const * std::size_t
 * wchar_t const * std::size_t
 * char16_t const * std::size_t
 * char32_t const * std::size_t
 *the return value however can be of any type
 */


#include<iostream>
// these unit translations still happens at run time so to minimise the runtime cost
// we can make it a constexpr now all these computations are done are compile time
//they wan't cost anything during the runtime
constexpr long double operator "" _cm(long double x) {return x*10;}
constexpr long double operator "" _m(long double x){return x*1000;}
constexpr long double operator "" _mm(long double x) {return x;}

// here we have a function which convert string binary to integer
constexpr int operator "" _bin(const char * str, size_t l)
{
        int ret=0;
        for(int i=0;i<l;++i)
        {
                ret=ret<<1;
                if(str[i]=='1')
                {
                        ret+=1;
                }
        }
        return ret;
}
int main()
{
        long double height=3.4_cm;//this is 3.4 cm
        std::cout<<height<<std::endl;// since our default is mm so the cm 3.4 is converted to mm and our output is 35
        std::cout<<(height+13.0_m)<<std::endl; // converts everyhing to mm and prints it
        std::cout<<(130.0_mm/ 13.0_m)<<std::endl;//user defined lieterals are convinent ways

        std::cout<<"110"_bin<<std::endl;
        std::cout<<"1100110"_bin<<std::endl;
        std::cout<<"110100010001001110001"_bin<<std::endl;
        return 0;
}
