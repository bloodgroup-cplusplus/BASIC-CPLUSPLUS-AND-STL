#include<iostream>
#include<string>
#include<memory>

class Dog
{
        std::string name_;
        public:
                Dog(std::string name){std::cout<<"Dog is created:"<<name<<std::endl; name_=name;}
                Dog(){std::cout<<"Nameless dog created."<<std::endl; name_ ="nameless";}
                ~Dog(){std::cout<<"dog is destroyed"<<name_<<std::endl;}
                void bark(){std::cout<<"Dog"<<name_<<"rules!"<<std::endl;}

};


void foo()
{
        std::shared_ptr<Dog> p1= std::make_shared<Dog>("Gunner"); // it is using default deleter: operator delete
        //std::shared_ptr<Dog> p2= std::make_shared<Dog>("Tank");
        // when p1 p2 get out of the scope both will be deleted in lifo order (stack)
        // if we do 
        //p1=p2;
        // both p1 and p2 are pointing to tank and gunner is deleted at this point
        //p1=nullptr; // gunner will also be deleted;
        //p1.reset(); // resets 
        // we shall se a case where we need to explicitly use the shared pointers constructor to create a shared pointer
        // one such case is when we have a custom deleter

        // when p1 goes out of scope it will call some delete function to delete the dog gunner
        // and that delete function is called a deleter
        // and by default the deleter is  the operator delete
        // and sometimes you want to use the different deleter in that case you need to use the constructor of the shared pointer
        std::shared_ptr<Dog> p2= std::shared_ptr<Dog> (new Dog("Tank"), [] (Dog *p){std::cout<<"Custom Deleting:"; delete p;});

        std::shared_ptr<Dog> p3(new Dog[3]);
        // p3 in this case is only managing the first dog
        // so when p3 goes out of scope only the first dog is deleted and other two dogs are leaked
        // dog[1] and dog[2] have memory leaks
        // in this case we need to use custom deleter
        std::shared_ptr<Dog> p4(new Dog[3], [] (Dog  *p) {delete[] p;}); // all 3 dogs will be deleted when p4 goes out of scope
        Dog *d=p1.get();// returns the raw pointer that shared pointer is managing
        // once you have created an object an assigned it to shared pointer you should avoid using the raw pointer
        // again
        // because the raw pointer provides you many ways of shooting yourself on the foot;
        // if do delete(d) the dog gunner will be deleted but when p1 goes out of scope 
        // dog gunner will be deleted again
        // which is an undefined operation
        //std::shared_ptr<Dog> p2(d);// when p2 goes out of scope dog gunner will be deleted. and when p1 goes out of scope, dog will be deleted again.
        //doghouse.saveDog(d); 
        //when p1 goes out of scope doghouse will be holding dangling pointer

}


int main()
{
        foo();
        return 0;
}

