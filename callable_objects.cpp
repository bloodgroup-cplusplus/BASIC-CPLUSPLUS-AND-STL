#include<iostream>
#include<thread>
#include<future>
class A
{
        public:
                void f(int x, char c){}
                long g (double x) {return 0;}
                int operator () (int N){return 0;}


};


void foo(int x)
{


}

int main()
{
        A a;
        // first way to launch a child object
        std::thread t1(a,6);
        // second way to launch a child object using an async function
        // both the thread construtor and async have the same signature
        // they take a callable objects followed by varied number of arguments
        // there is another function that has similar signature
        //std::async(std::launch::async, a,6);
        //std::bind(a,6);
        //std::call_once(std::once_flag, a,6);
        // calling callable objects followed by variable arguments is very popular in standard library
        // how this can be used in different ways
        // the first line std::thread t1(a,6) is creating a thread and invoking the functor
        // copy_of_a () in a differnt thread
        // copy_of_a() in a different thread
        std::thread t2(std::ref(a),6);// create a refrence wrapper of a and pass it over to the next thread
        // this will simply launch a as a functor in different thread
        // we can also create an  A on go;
        std::thread t3 (A(),6); // this creates temporary A and it is moved to the object
        //the callable object can also be a regular function and a lambda function
        std::thread t4([](int x) {return x*x;} , 6);
        std::thread t5(foo,7);
        // we can also create a thread with member functions
        std::thread t6(&A::f, a, 8,'w');// this is again making a copy_of_a and invoking a.f(8,'w') in a different thread
        // if we don't want to make a copy of a
        std::thread t7(&A::f, &a, 8,'w'); // a.f (8,'w') in a different thread
        std::thread t8(std::move(a),6);//a is no longer usable in main thread
        //these are differnt ways of using the callable object
        //they can also be used for bind and async function
        //std::bind(), std::async(); std::call_once();

        return 0;
}


~                                                                                                                 
~                                                                                                                 
~                                                                                                                 
~                                
