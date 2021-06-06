#include<iostream>
#include<memory>
#include<string>
class Dog
{
        // dog has a  new member as a shared pointer
        // it also has a member function called m_pFriend;
        //std::shared_ptr<Dog> m_pFriend;
        std::weak_ptr<Dog> m_pFriend;
        public:
                std::string m_name;
                Dog(std::string name) {std::cout<<"Dog is created"<<name<<std::endl; m_name= name;}
                void bark() {std::cout<<"Dog"<< m_name<< "rules!" <<std::endl;}
                ~Dog() { std::cout<<"Dog is destroyed:"<<m_name<<std::endl;}
                void showFriend(){if(!m_pFriend.expired())std::cout<<"My friend is :"<<m_pFriend.lock()->m_name<<std::endl;
                        std::cout<<"He is owned by"<<m_pFriend.use_count()<<"pointers"<<std::endl;
                }

                // in order to use the weak pointer we do need to use the function .lock()
                // we cannot directly print it out
                // what the lock function does is it creates a shared pointer out of the weak pointer
                // why does it do that ?
                // to make sure that weak pointer is still pointing to a valid object
                // and 2 it makes sure that while accessing that object it is not deleted
                //also check if m_pFriend is not expired else it throws an error
                //weak pointer also provides an api to show how many shared pointers are pointing to that object
                //we have an api called usecount

                void makeFriend(std::shared_ptr<Dog> f){m_pFriend =f;}
};


int main()
{
        std::shared_ptr<Dog> pD( new Dog("Gunner"));
        std::shared_ptr<Dog> pD2( new Dog("Smokey"));
        pD->makeFriend(pD2);
        pD2->makeFriend(pD);
        pD->showFriend();
        // when we run the above program we see that the objects are not deleted despite declaring a shared pointer
        // this happens due to a phenomenan called as cyclic refrence
        // gunner has a shared pointer which is pointing to smokey
        // and smokey also has a shared pointer which points to gunner
        // this forms a cylce and none of the shared pointers will ever go out of scope
        // and none of the dog will ever be deleted
        // the solution is to use weak pointer
        // so instead of using shared_ptr in our class
        // we instead use weak pointer
        //now both smokey and gunner are destroyed
        // shared pointer provides a shared ownership of an object and what the weak pointer says is when and how that object will be deleted is not the case
        // having a wweak pointer is similar to having a raw opinter alongwith a level of protection which ensures nobody can use the operator delete on this pointer
        // as a result of this concept weak_pointer is not always is valid
        // if the object that weak pointer is pointing to is deleted the pointer becomes an empty pointer
        // so another level of protecton provides is a safer acces to the pointer

        return 0;
}
