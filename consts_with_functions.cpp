#include<iostream>
#include<string>
class Dog
{
        int age;
        std::string name;
        public:
                Dog(){age=3; name="dummy";}
                //here the setAge function just sets the value of age to a 
                //but let's say it is also used in incrementing the value of a by 1
                void setAge(const int &a) {age=a;}
                //when we increment the value of a in setAge the value of i in the main function also changes so whenever we do a++ the value of i changes and we get 10 in the main function instead of 9. What can be done to prevent this// to do this we pass the parameter as const int &a;

        // if we do use the const word without sending the refrence only sending the value
        // i.e.,setAge(const int a) and say we have another function
        // void setAge(int a) {age=a;}
        // void setAge(const int a){age=a;}
        // then the compiler will not recognize which function was actually called


        // now we have a function which returns a const string refrence

                const std::string & getName() {return name;}
        // the reason we return a const string refrence is the same reason why we wan't a const refrence parameter
        // doing this the caller cannot change the value


        // let's see a const function
        // const function is a fuctiion which doesn't change the value of any variables of the given class

        // even if there is a function call inside this function and the called function is not
        // a const function then the code doesn't compile
        // a const function can only call const function to mantain the correctness
        // now let's say we have functions with same name and signature
        // one is const and other aint
        // so how do we differentiate
        // the idea here would be to declare a const class object to call the const function
        // and a normal class object to call the normal class

        void  printDogName() {std::cout<<getName()<<"const"<<std::endl;}
        void printDogName() const{ std::cout<<name<<std::endl;}



        // a function that takes a const reference parameter can also be overloaded with a function that takes a refrence parameter


        // above we have a setAge(const int &a){age=a;}
        // let's delcare another age

        void setAge(int &a) {age=a;}
        // this is an example of lvalue and  rvalue ( which function to call depends on the concept of rvalue and lvalue refrence idea);
        //
};


int main()
{
        Dog d;
        int i=9;
        d.setAge(i);
        std::cout<<i<<std::endl;
        const std::string &n=d.getName();
        std::cout<<n<<std::endl;
        d.printDogName();
        const Dog d2;
        d2.printDogName();
    
