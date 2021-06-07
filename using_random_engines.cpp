/* random engine:
 *    stateful generator that generates random values within predefined min and max
 *    Not truely random -- it is pseudorandom i.e., nothing computer generates is truly random
 *
 *
 */


#include<random>
#include<iostream>
#include<sstream>
#include<chrono>
#include<vector>
#include<algorithm>
void printRandom(std::default_random_engine e)
{
        for(int i=0;i<10;++i)
        {
                std::cout<<e()<<std::endl;
        }
        std::cout<<std::endl;
}

int main()
{
        std::default_random_engine eng;
        // we create a default random_engine and print out min and max value it can generate
        std::cout<<"Min :" <<eng.min()<<" Max:" <<eng.max()<<std::endl;
        // this min to max is the range of data
        //now let's generate the random value;
        std::cout<<eng()<<std::endl;
        // eng() is simply a functor
        //this will generate one random value
        std::cout<<eng()<<std::endl;
        //and the engine has an internal state to show what kind of random value it will generate
        std::stringstream state;
        state<< eng; // this will save the current state 
        std::cout<<eng()<<std::endl;
        std::cout<<eng()<<std::endl;
        state>> eng; // Restore the state . It will restore the engine's state to the variable
        std::cout<<eng()<<std::endl;
        std::cout<<eng()<<std::endl;
        // the above two values are the same values
        // if the engine is in the same state if will generate same value;      
        std::default_random_engine e;
        std::default_random_engine e2;
        printRandom(e);
        printRandom(e2);
        //both the engines prints out the same values
        //when they were created they were in the same initial state
        //we don't wan't the random engines to generate same sequence of values
        //everysingle time we want themm to be as random as possible
        // so to do this we need a seed
        unsigned seed =std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine e3(seed);//since the above value of seed is different for differnt times so the seed value is always different
        // e3 will always generate a different sequence of numbers
        printRandom(e3);
        //seed is a number that determines different state of the engine
        e.seed();// this will reset engine to initial state
        e.seed(109);// this will set engine e to state accroding to seed 109
        e2.seed(109);
        if(e==e2)
        {
                std::cout<<"e and e2 have the same state"<<std::endl;
        }
        //this can also be used to shuffle a vector or a deque
        std::vector<int> d={1,2,3,4,5,6,7,8,9};
        std::shuffle(d.begin(),d.end(),std::default_random_engine());
        std::cout<<"The shuffled vector is "<<std::endl;
        for(auto & x:d)
        {
                std::cout<<x<<" ";
        }
        std::cout<<std::endl;
        return 0;

}

