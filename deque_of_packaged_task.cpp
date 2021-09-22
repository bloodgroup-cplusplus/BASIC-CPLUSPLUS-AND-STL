#include<iostream>
#include<functional>
#include<future>
#include<thread>
#include<deque>
#include<list>
std::mutex mu;
std::condition_variable cond;
std::deque<std::packaged_task<int()> > task_q;
int factorial(int N)
{
        int res=1;
        for(int i=N; i>1;--i)
        {
                res*=i;
        }

        std::cout<<"Result is "<<res<<std::endl;
        return res;
}
void thread_1()
{
        std::packaged_task<int()> t;
        {
                std::unique_lock<std::mutex> locker(mu);
                cond.wait(locker,[]{return !task_q.empty();});
                t=std::move(task_q.front());
                task_q.pop_front();
        }
        t();
}

int main()
{
        std::thread t1(thread_1);
        std::packaged_task<int()> t(std::bind(factorial,6));
        // we declare a thread which will pop off the task and execute it in the required time
        std::future<int> fu=t.get_future();
        {
                std::lock_guard<std::mutex> locker(mu);
                task_q.push_back(std::move(t));
        }
        task_q.push_back(t);
        cond.notify_one();
        std::cout<<fu.get();
        t1.join();
        return 0;
        // the main thread will create a task and push it into the dque q and when thread 1 will pop off the task from the queue and execute it
        // when the task is executed. it generates a return value
        // how do i get the return value if we wan't to return the value to the main thread
        // we can use the task t to create a future
        // since our program data is shared between two threads there is a data race condition
        // we need to use the mutex in order 
        // since the thread t is no longer used in the the main we can move it to the task q
        // also the thread 1 might call the front function before the main calls the push_back function
        // i.e, there could be pop call before anyting is pushed in the queue
        // so we need to make sure the front function is called after push_back function 
        // so to do that we need a std::conditional_variable
        // different ways of getting a future
        // * 3 ways to get a future
        // -promise::get_future()
        // -packaged_task::get_future()
        // -async() returns a future
        // i
}


