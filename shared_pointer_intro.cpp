#include<iostream>
#include<string>
#include<memory>

class Dog
{
        std::string name_;
        public:
                Dog(std::string name){std::cout<<"Dog is created:"<<name<<std::endl; name_=name;}
                Dog(){std::cout<<"Nameless dog is created"<<std::endl; name_="nameless";}
                ~Dog(){std::cout<<"dog is destroyed"<<name_<<std::endl;}
                void bark(){std::cout<<"Dog"<<name_<<"rules!"<<std::endl;}
};

void foo()
{
        //Dog * p= new Dog("Gunner");
        // now if we delete p
        // i.e., delete p
        // and call a function of the Dog class
        // p->bark(); // then p becomes a dangling pointer
        // this causes memory leak
        // the trouble here is we were not able to delete the dog early we have a dangling pointer
        // if we don't delete the dog at all we have a memory leak
        // but the problem is keeping track of when to delete every object. that is not only hard
        // but is a tedious thing to keep track of
        // this is why we need smart pointers
        // this mainly  includes shared pointer
        // the way to use the shared pointer is easy

        std::shared_ptr<Dog> p(new Dog("Gunner"));
        //the way shared pointers work is it keeps track of how many shared pointers are pointing         // to the object
        //and when that number becomes zero that object will be deletted automatically
        //write now the count is one
        // count=0
        // whne foo is called
        // in this case the pointer is not shared
        //the shared pointer by default is not shared now let's create a secenario where we have the shared pointer shared by another object
        //
        {
                std::shared_ptr<Dog> p2=p; //Count=2;
                p2->bark();
                // shared pointers also have some member functions which show how many member functions are pointing to the object i.e.
                std::cout<<p.use_count()<<"\n";// this uses 2;
                // -> is used to access objects members
                // and "." is used to access shared pointers itselfs members
                //
        }

        // after p2 goes out of scope the count becomes 1 again
        // by the end of foo function the count becomes 0 and the dog is destroyed
        // call foo from main and print out the results;

}


int main()
{
        foo();
        Dog * d= new Dog("Tank");
        //std::shared_ptr<Dog> p(d);
        //std::shared_ptr<Dog> p2(d);
        //on executing the above statement(s) one would think that p and p2 are shared ponters pointing to the class and when p and p2 goes out of scope the class tan will be destroyed
        //but the above is a very bad way of using a shared pointer
        //what has happened is when p is constructed from dog value d p has the count value 1
        //p.use_count()==1
        //and when p2 is constructed from the dog pointer itself, it also mantains a count of 1
        //i.e., p2.use_count()==1;
        //when p gets out of scope the dog tank will be destroyed
        //but when p2 gets out of scope the dog tank will be destroyed again
        //which is an undefined behaviour.
        //the key thing about using a shared pointer
        //An object should be assigned to a smart pointer as soon as it is created
        //Raw pointer should not be used again andd in the above case
        //so using it that way is a bad idea
        //because this issue is so important c++ provides short-cut way of wrapping an object with shared pointer
        //so the short-cut is like this
        //shared_ptr<Dog> p=make_shared<Dog>("parameters that you used to construct the class");
        //this is the preferred way of creating a shared_pointer
        std::shared_ptr<Dog> p = std::make_shared<Dog>("Tank");// this is faster and safer
        return 0;
}
