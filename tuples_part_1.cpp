#include<utility>
#include<tuple>
#include<string>
#include<iostream>
#include<memory>
int main()
{
        std::pair<int, std::string> p=std::make_pair(12,"hello");
        std::cout<<p.first<<" "<<p.second<<std::endl;
        // tuple is an extension of pair
        std::tuple<int, std::string, char> t(32,"pennywise",'a');
        std::cout<<std::get<0>(t)<<std::endl;
        std::cout<<std::get<1>(t)<<std::endl;
        std::cout<<std::get<2>(t)<<std::endl;
        std::get<1>(t)= "Pound foolish";
        // get function returns a refrence to the variable stored in the tuple
        std::string &s= std::get<1>(t);
        s="Patience is a virtue"; // changes the tuple t;
        std::cout<<std::get<1> (t) <<std::endl;
        int i=1;
        //get<i>(t); // this doesn't work as i must be a compile time constant
        //creating a tuple without initializing
        //std::tuple<int, std::string, char> t2; // every member is constructed with a default constructor
        std::tuple< int , std::string , char> t2; // default constructor
        t2= std::tuple <int, std::string,char> (12,"curiosity kills the cat",'d');
        t2= std::make_tuple(12,"curiosity kills the cat",'d');
        if(t > t2) {// lexicographical comparision
                std::cout<<"t is larger than t2"<<std::endl;
        }
        // as 32 is larger than 12 it will have print the above statement
        t=t2; // this assignment does a member by member copy
        //tuple can store refrences this is only container store refrences
        std::string st= "In for a penny";
        std::tuple<std::string &> t3(st);
        std::get<0>(t3)= "In for a pound";
        std::cout<<"The refrence of st is changed  st is now a new string  " <<st<<std::endl;
        t3=std::make_tuple(std::ref(st)); // we need to create a refrence wrapper for st and pass it
        int x;
        std::string y;
        char z;
        t2=std::make_tuple(12,"Curiosity kills the cat",'d');
        std::make_tuple(std::ref(x),std::ref(y),std::ref(z))=t2;
        std::tie(x,y,z)=t2; // doing the same thing
        std::tie(x,std::ignore, z)=t2;//the string value will be ignored

        // tuples can also be concatinated

        auto t4= std::tuple_cat(t2, t3); // t4 is a tuple of <int, sting, char, stringref>
        // tuple also has a dedicated traits

        std::cout<<std::tuple_size<decltype(t4)>::value<<std::endl;
        std::tuple_element<1,decltype(t4)>::type d; // d is a string
        std::cout<<d<<std::endl;

        return 0;
}

