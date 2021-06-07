#include<iostream>

class dog
{
        int age;
        public:
                dog(int age);
                dog()=default; // force compiler to generate the default constructor;
                void show_age(){std::cout<<"Hola soy " << age<< " tiene anos"<<std::endl;}
};


int main()
{
        dog g;
        g.show_age();
        return 0;
}
                     
