#include<iostream>
#include<deque>

class Dog
{
        public:
        virtual void bark() { std::cout<<" I do not have a name"<<std::endl;}
};


class Yellowdog: public Dog
{
        std::string m_name;
        public:
                Yellowdog(std::string name):m_name(name){}
                void bark(){std::cout<<"My name is "<<m_name<<std::endl;
                }
};

void foo(Dog d){}

int main()
{
        std::deque<Dog>d;
        Yellowdog y("Gunner");
        d.push_front(y);
        d[0].bark();
        // the above code actually should generated the output
        //
        // "My name is gunner"
        // but when we run the code
        // the output we get is "I don't have a name"
        // what happens is that since d is a deque of dog,
        // when we push front the object of yellow dog (i.e.,y)
        // it doesn't put it 
        // it takes y as a parameter and copy constructs a dog
        // and pushes new constrcuted dog to deque d
        // d[0] is now a dog
        // this process is called object slicing
        // what is being pushed to d is called as a sliced version of y
        // so to do that we can do it by making the following changes
        // also make the bark function on the parent class as virtual
        std::deque<Dog*> d1;
        Yellowdog y1("Gunner1");
        d1.push_front(&y1);
        d1[0]->bark();
        return 0;
        // when object is passed by value slicing might happen because of the static cast
        // if we don't want the slicing to happen pass it by the refrence
        // if we don't make the bark function on the parent class a virtual
        // we can see that d is the deque of dog class
        // and when we push the yellow dog into it the static cast still happens
        // but the cast only happens to pointer not to the yellow dog itself
        // object slicing happens in another instance as well
        //
        Dog d2=y;
        foo(y); // again slicing takes place
}
