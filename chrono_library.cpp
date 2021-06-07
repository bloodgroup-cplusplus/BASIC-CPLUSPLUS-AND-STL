//chrono is library to deal with time and data
//the previous libraries all  suffer from a problem of precision
//-- a precision-neutral library for time and date
//no matter what kind of precision you want to use the library always satisfies that precison
//--A precison-neutral library for time and date ms/micros/picos/nano-s
//and it does by separating the duration and time points from the clocks
//Clock: what is clock? chrono provides three clocks
//first clock is system clock
//std::chrono::system_clock: tells me the current time according to the system- it is not steady
//std::chrono::steady_clock: goes at a uniform rate always runs at unifrom rate
//since system clock is not steady
//std::chrono::high_resolution_clock: provides smallest possible tick period
//it is basically typedef of system clock
//the most important attribute of the clock is its frequency
//the clock's period is represnted with a ratio
//we can find the period of the system clock by using the ratio method
//
//std::chrono::duration<>:represents time duration
//say we wan't to represent two hours
// so this are two things we need a number and a unit 
// duration<int,ratio<1,1> > //this duration can be used to represent number of seconds stored in a int
// duration<double,ratio<60,1>> // this can represent number of minutes stored in double
// chrono also has convinient typedefs nanoseconds,microseconds,milliseconds,seconds, minutes,hours etc
// each one of the clock has own predefined duration
// e.g., system clock has duration of type t
// system_clock::duration -- duration<T, system_clock::period>
//
//
//
//std::chrono::time_point<> ; represents a point of time
//00:00 January 1, 1970 (Coordinated Universal Time -UTC) --epoch of a clock
// a point of clock could be represented as a duration which respect to the epoch of the clock
// time_point<system_clock,milliseconds>;//according to system_clock, the elapsed time since epoch in milliseconds.
// system_clock::time_point --time_point<system_clock, system_clock::duration>
// steady_clock::time_point --time_point<steady_clock, steady_clock::duration>

#include<chrono>
#include<iostream>
int main()
{
        std::ratio<1,10> r;// 1/10
        std::cout<<r.num<<"/"<<r.den<<std::endl;
        std::cout<<std::chrono::system_clock::period::num<<"/"<<std::chrono::system_clock::period::den<<std::endl;
        std::chrono::microseconds mi(2700); //2700 microseconds
        std::chrono::nanoseconds na= mi; // 2700000 nanoseconds
        //to convert from higher duration to lower duration i.e., to convert from microseconds to milliseconds we need extra code
        std::chrono::milliseconds mill=std::chrono::duration_cast<std::chrono::milliseconds>(mi);//2milliseconds
        // the value is actually truncated
        mi=mill+mi; // 2000+2700=4700
        std::chrono::system_clock::time_point tp= std::chrono::system_clock::now();// this shows the current time of system clcok
        // to print out the current time of the system clock
        std::cout<<tp.time_since_epoch().count()<<std::endl;// number of 100 nano seconds since time of epoch
        tp=tp+std::chrono::seconds(2);//add 2 seconds to the current time of my system clock
        std::cout<<tp.time_since_epoch().count()<<std::endl;
        // the difference between the above 2 values should be 2 seconds only ( answer is in nanoseconds)
        std::chrono::steady_clock::time_point start=std::chrono::steady_clock::now();
        std::cout<<"I am bored" <<std::endl;
        std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
        //now we have two start points and can get the duration by getting the difference between
        //the two time points
        std::chrono::steady_clock::duration d= end-start;
        if(d==std::chrono::steady_clock::duration::zero())
        {
                std::cout<<"no time elapsed"<<std::endl;
        }
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(d).count()<<std::endl;


        return 0;
}
