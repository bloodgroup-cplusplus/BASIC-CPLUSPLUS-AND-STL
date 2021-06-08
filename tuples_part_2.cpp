#include<tuple>
#include<string>
#include<memory>
#include<map>
#include<iostream>
#include<unordered_map>
std::tuple<std::string, int> getNameAge()
{
        return std::make_tuple("Bob",34);
}

int main()
{
        // why tuple when there is struct
        //
        // we could easily do 
        // struct person { string name; int age;}  P;
        // std::tuple<std::string, int> t;
        //std::cout<<p.name<<" "<<p.age<<std::endl;
        //std::cout<<get<0>(t)<<" "<<get<1>(t)<<std::endl;
        //which one is better struct or tuple
        //struct is more clear like it explicitly mentions its variables i.e, p.name etc.
        //using struct is more readable
        //tuple is useful as a one-time only structure to transfer a group of data
        std::string name;
        int age;
        std::tie(name, age)=getNameAge();
        //using this tuple makes it a one time structre to transfer a group of data
        //we can also compare tuples
        std::tuple<int,int,int> time1, time2; // hours, minutes, seconds
        if(time1 > time2)
        {
                std::cout<<"time1 is  a later time"<<std::endl;
        }

        // we can also use tuples in map to denote multiinidex maps
        std::map<std::tuple<int,char,float> ,std::string> m;
        m[std::make_tuple(2,'a',2.3)]="Faith will move mountains";
        // we can also use tuple to create multindex hashtable
//      std::unordered_map<std::tuple<int,char,float>, std::string>  has;
        int a,b,c;
        std::tie(b,c,a)=std::make_tuple(a,b,c);
        return 0;
}
