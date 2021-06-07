// whenever we declare an empty class
// class xyz{};
// the compiler generates some functions by default
// they are
// 1)default constructor(generated only if no constructor is declared by user)
// 2)copy constructor( generated only if no 3,4,5,6 is declared by user)
// 3)copy assignment operator(generated only if 2,4,5,6 not are declared by user)
// 4)destructor
// 5)move constructor(generated only 2,3,4,6 not declared by user)
// 6)move assignment operator(generated only if 2,3,4,5 not declared by the user)
// the first four were on c++ 03 and all of them on c++ 11 and onwards
// so the empty class dog we declared above is similar to class below
// class Dog
// {
//      Dog(); //default constructor
//      Dog(const Dog &); //copy constructor
//      Dog & operator =(const Dog &) copy assignment operator
//      ~Dog(); destructor
//      Dog(Dog &&) // a move constructor
//      Dog & operator =(Dog &&); //move assignment operator
// };

class Cat // only 3 and 4 (3 is deprecated)
{
        public:
                Cat(const Cat&){}// copy constructor
};

class Duck// 4 only copy and cannot be copied and only be moved
{
        Duck (Duck&&){} // move constructor
};


class Frog//4 only destructor generated so similar to duck
{
        Frog (Frog &&, int =0) {} // this function is actually a move constructor when the second parameter is  not specified it cannot 
        Frog(int=0){}//default constructor
        Frog(const Frog &, int=0){}//copy constructor

};


class Fish

{
        ~Fish(){} //everthing except move constructor and move assignment operator is generated
// 2 and 3 are depreceted
};

class Cow {//1,2,4 (move constructor and move assignment is not generated 2 is deprecated
        Cow & operator =(const Cow&)=delete;
        Cow (const Cow &)=default //brings compiler generated copy constructor back
        // we have deleted copy assignment operator but it is still counted as copy assignement operator by user.

};

~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
~                                                                                          
