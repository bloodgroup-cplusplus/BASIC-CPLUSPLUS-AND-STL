#include<iostream>
#include<thread>
#include<time.h>
#include<mutex>
#include<condition_variable>
#include<future>
#include<chrono>
int factorial(int N)
{
        int fact=1;
        for(int i=1;i<N;++i)
        {
                fact*=i;
        }
        return fact;

}



int main()
{
        /*thread*/
        std::thread t1(factorial, 6);

        // any thread can sleep for certain amount of time
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        std::chrono::steady_clock::time_point tp=std::chrono::steady_clock::now()+std::chrono::microseconds(4);
        //which is equal to current time of steady clock + microseconds
        std::this_thread::sleep_until(tp);

        /* Mutex*/

        std::mutex mu;
        std::lock_guard<std::mutex> locker(mu);
        std::unique_lock<std::mutex> ulocker (mu);
        // unique lock can lock and unlock the mutex multiple times
        // it can also transfer ownership from one unique lock to another
        ulocker.try_lock();// this will try to lock the mutex and if it is not successful it will immediately return
//      ulocker.try_lock_for(std::chrono::nanoseconds(500)); // this this case if 500 has passed and the mutex still cannot lock then the
        //function will return
//      ulocker.try_lock_until(tp); // a certain time point

        /*conditional Variable*/
        //synchronize the exectution order of threads
        std::condition_variable cond;
//      cond.wait_for(std::chrono::microseconds(2));
        cond.wait_until(ulocker,tp);//tp is the time pointer

        /* Future and Promise*/
        std::promise<int> p;
        std::future<int> f=p.get_future();
        f.get();
        f.wait();//waits for the data to be available
        //get function will call the wait function
        f.wait_for(std::chrono::milliseconds(2));
//      f.wait_until(2);

        /*Async Function is another way to spawn a thread*/

        std::future<int> fu=std::async(factorial,6);

        /*Packaged tasks*/
        //class template parametreized with function signature of task we are going to create
        //later on the task can be executed the same way we run function
        //task can also return a future

        std::packaged_task<int(int)> t(factorial);

        std::future<int> fu2=t.get_future();
        t(6);
        //these are the threading utilities standard libraries
        //we can add time// constraints to utilitiy functions by using the chrono library.
        return 0;
}
