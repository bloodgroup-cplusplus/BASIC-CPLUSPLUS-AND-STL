#include<iostream>
#include<chrono>
#include<sstream>
#include<vector>
#include<random>
#include<string>
int main()
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::cout<<e()<<std::endl;
        // the problem with the above way of generating random numbers is it only generates it in the range (e.min().e.max())
        //let's set a range [0,5]
        std::cout<<e()%6<<std::endl;
        // 1. Bad quality of randomness
        // 2. This approach can only provide unifrom distribution
        // 3. If you wan't number to be evenly generated from 0 to 5 we can get it
        // 4. If we want some normal distribution then there is no way to get it
        // 5. So we need distribution
        std::uniform_int_distribution<int> distr(0,5);//This will generate random numbers in range of [0,5] 
        // most of the time the range is half open notation but the above is a special case
        std::cout<<distr(e)<<std::endl;
        // the random engine e provides a source of randomness
        // the distr provides a way to distribute certain number with ceratin probability
        // this is generating a random interger value
        //
        // to generate a real value
        std::uniform_real_distribution<double> distR(0,5); // Range;[0,5)
        std::cout<<distR(e)<<std::endl;

        std::poisson_distribution<int> distrP(1.0);//mean
        std::cout<<distrP(e)<<std::endl;
        //let's create a normal distribution which takes a mean and a standard deviatioin
        std::normal_distribution<double> distrN(10.0,3.0);//mean and standard deviation
        std::vector<int> v(20);
        for(int i=0;i<800;++i)
        {
                int num=distrN(e); // convert double to int
                if(num>=0 && num<20)
                {
                        v[num]++; //E.g., v[10] records number of times 10 appeared
                }
        }
        for(int i=0;i<20;++i)
        {
                std::cout<<i<<": " <<std::string(v[i],'*')<<std::endl;
        }
        std::cout<<std::endl;
        return 0;
}
