#include<iostream>

class dog
{
        public:
                dog(int age){}
                dog(double)=delete;
                dog & operator =(const dog &)=delete;


};

int main()
{
        dog a(2);
        dog b(3);
        // whenever we try to call with any other datatype rather than int
        // it will generate an error
        //dog(3.0232);

        return 0;
}
