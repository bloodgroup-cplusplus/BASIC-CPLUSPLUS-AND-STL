#include<iostream>
#include<memory>
#include<string>

class Dog
{
        public:
                std::string m_name;
                void bark(){std::cout<<"Dog"<<m_name<<"rules!"<<std::endl;}
                Dog(){std::cout<<"Nameless dog created"<<std::endl; m_name="nameless";}
                Dog(std::string name){std::cout<<"Dog is created:"<<name<<std::endl; m_name=name;}
                ~Dog(){std::cout<<"dog is destroyed:"<<m_name<<std::endl;}
};





void test()
{
        //Dog * pD =new Dog("Gunner");
        //this is the old fashioned way
        //the problem is if we write a try catch block here and it returned to the main function 
        //before even getting deleted then there is a chance of memory leak
        //either case the dog will not be deleted
        //the dog's solution will be leaked
        //use unique pointer to manage the dog
        //
        std::unique_ptr<Dog> pd( new Dog("Gunner"));
        pd->bark();
        Dog * p= pd.release();
        //after calling the release function pd has given the ownership of dog and as a result
        //nobody owns the dog anymore and nobody will own it
        //delete pD;
        // we can also check if pd is a null pointer
        if(! pd)
        {
                std::cout<<"PD is empty"<<std::endl;
        }
        // now we reset pd to a new pointer
        pd.reset(new Dog ("Smokey"));
        if(! pd)
        {
                std::cout<<"pd is empty;\n";
        }

        else
        {
                std::cout<<"Pd is not empty\n";
        }

        // first unique pointer is destroyed when the pointer is reset
        // the second pointer is destroyed when the function test stops executing
        // if we don't pass any parameter to the reset () 
        // it has same affect as setting  it to a nullptr
        // reset function destroy the original object and release doesn't destroy
        // two unique pointers cannot share the same object at the same time but could share at different time
        //
        std::unique_ptr<Dog> pD(new Dog("Gunner"));
        std::unique_ptr<Dog> pD2(new Dog("Smokey"));
        pD2->bark();
        pD2= move(pD);
        // this line of code has three consequences
        // 1 Smokey is destroyed
        // 2 pD becomes empty
        // 3 pD2 owns Gunner
        // this is how we transfer ownership from one unique pointer to another unique pointer
        //
        pD2->bark();


}


int main()
{
        // a unique pointer represents exclusive ownership of an object
        // so unlike the shared pointers where mulitple shared pointers can share the stuff of unique objects
        // one object can only be owned by one unique pointer
        // when it goes out of scope the original object will automatically be deleted
        // unique pointer is light weight smart pointer
        // unique pointers have exclusive ownership
        //unique function has release function which returns the raw pointer
        //shared functions get doesn't give out the ownership
        //but shared functions.release does give out the ownership
        //no
        test();
}
