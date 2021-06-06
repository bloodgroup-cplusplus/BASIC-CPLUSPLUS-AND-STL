#include<iostream>
#include<future>
#include<thread>
#include<functional>
int factorial( int N)
{
        int res=1;
        for(int i=N; i>1;--i)
        {
                res*=i;
        }

        std::cout<<"Result is:"<<res<<std::endl;
        return res;
}




int main()
{
        // we create a packaged task t with the factorial function
        // t is a task being packaged up and it can be passed along to differnt function or different
        // object or different thread
        // so after this many things could happend
        //
        std::packaged_task<int(int)> t(factorial);
        t(6);// the task can be executed in different context
        //packaged task can be transferred anywhere in the progarm and can be executed there
        //a packaged task is template class parameterized with function signature of this task
        //t(factorial) //factorial is the signature
        //when task is executed it also needs to take the integer parameter
        int x=t.get_future().get();
        //the above line will give the return value from the factorial function
        std::thread t2(factorial, 5);
        // we cannot send additional parameter into the consturctor like threads in case of packaged tasks
        std::packaged_task<int()>t1 (std::bind(factorial,6));
        // we instead  need to create a function object using "bind" to carry out the factorial function
        // new constructed function object cannot take parameter anymore as it is already bundled
        t1();
        // a packed task is created differently than the thread is created
        auto m=std::bind(factorial,6);
        // the main advantage of packaged task is it can link callable object to a future which is important to a threading environment

        return 0;
}
~   
