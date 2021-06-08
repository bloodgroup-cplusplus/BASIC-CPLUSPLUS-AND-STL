#include<vector>
#include<string>
#include<iostream>
#include<string>
#include<memory>
class Person

{
        public:
                Person(std::string name) : pName_(new std::string(name)){}
                Person (Person &&)=default;
//              Person( const Person &) =delete; // the copy constructor is deleted
                //~Person() {delete pName_;}
                ~Person(){}
                void printName() { std::cout<<*pName_<<std::endl;}

        private:
                std::unique_ptr<std::string> pName_;
                // with shared pointer we don't need to define the copy constructor
                // we don't need to define the copy assignment operator
                // and we don't need to define the destructor
                // yet we can manage the resources safely
                // like the shared pointer the unique pointer will also destroy the pname
                // the unique pointer is a much more  lightweight resource as compared to 
                // the shared pointer
                // the unique pointer is much less costly
                // unique pointer cannot be copied it can only be moved
};


int main()
{
        std::vector<Person> persons;
        Person p("George");
        //persons.emplace_back("George"); // construct the object in place in the space allocated to the vector so there is no copying or moving 
        persons.push_back(std::move(p));
        persons[0].printName();
        std::cout<<"Goodbye"<<std::endl;
        return 0;
}
