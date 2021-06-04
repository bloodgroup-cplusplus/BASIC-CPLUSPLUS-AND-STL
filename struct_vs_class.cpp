// in case of a struct the data members are public
// in case of a class the data members are private
// usually struct is used for small passive objects that carry public data
// and have no or few basic  member functions
// DAta container
// Class is used for bigger active objects that carry private data, interfaced through public member functions
// class is a complex data structure
// struct Person_t
// {
//      string name;// public
//      usigned age;
//      private:
//              int height
//
// }
// class Person
// {
//      string name_;//private
//      unsigned age_;
//      public:
//              usigned age()const{return age_;}//getters are always const/accessor
//              void set_age(unsigned a){age_=a;}//setter
// };
//
// class data members are named that the way we truly understand
// struct data members are named the same way we name a regular variable
// say in the main function  we create the struct variable
// int main()
// {
//      Person_t PT;
//      cout<<PT.age;
//      Person P;
//      cout<< P.age // this will not compile as it is a private variable
//      Person P;
//      cout<<P.age();
//      P.set_age(4);
// } 
//when we create object oriented code we want to seperate the interface from the implementation
//we want to encapsulate the implementation we only wan't to talk via interfaces
//if we make data members public then we are exposing the internal implementation
//to the outside world
//which will bring a lot of headache
//if you wan't to add some age to setting  the rule then you can add the set function
//too many of getter and setter is not a good practice if we need to provide getter and setter for many data members
//having too many of setters and getters indicate some problem with my design
//in general avoid using setters and getters(too many getters and setters)
//what is the trailing underscores i.e., that is due to the fact that using trailing underscores are the official 
//starting underscore is officialy used for private variables _ and __ starting
//
// Summary:
//      Use struct for  passive objects with public data, and use class for active objects with private data;
// Use setter/getter to access class's data
// Avoid making setter/getter if possible

//This is the final source code

#include<string>
#include<iostream>
struct Person_t
{
        int age;
        std::string name;
};

class Person
{
        std::string name_;
        unsigned age_;
        public:
                unsigned age()const{return age_;}
                void set_age(unsigned a){age_=a;}
};
int main()
{
        Person_t PT;
        std::cout<<PT.age<<"\n";
        Person p;
        p.set_age(21);
        std::cout<<p.age()<<"\n";
        return 0;
}
