//This program shows off the basics of RAII with locks
//By: Nick from CoffeeBeforeARch
//
#include<mutex>
#include<thread>
#include<iostream>

//declare our mutex
//
std::mutex my_mutex;

//Function executed by multiple threads
//
void print_func()
{
        my_mutex.lock();
        std::cout<<"Printing from a thread!\n";
        //what if an exception happens and we never reach the exception portion of the code
        //so that can be dangerous
        my_mutex.unlock();

}

//Function executed by multiple threads but with a lock guard.
//
void better_print_func()
{
        std::lock_guard<std::mutex> g(my_mutex);
        // when lock guard goes out of scope, it automatically frees the vertex.
        // for the reason we might forget to unlock.
        //creation of lock guard makes sure that mutex gets unlocked
        //
        std::cout<<"Printng from a thread!\n";
}


int main()
{
        //Call our old-fashioned function
        //
//      std::thread t1(print_func);
//      std::thread t2( print_func);
//      t1.join();
//      t2.join();

        //Call our better function using RAII

        std::thread t3(better_print_func);
        std::thread t4(better_print_func);
        t3.join();
}
