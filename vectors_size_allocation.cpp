#include<iostream>
#include<deque>
#include<vector>
class Dog{};
int main()
{
        std::vector<int> vec={2,3,4,5};
        std::cout<<"vec size  "<<vec.size()<<std::endl;
        std::cout<<"vec's capacity " <<vec.capacity()<<std::endl;

        vec.push_back(6);
        std::cout<<"After push_back(6) " <<vec.size()<<std::endl;
        std::cout <<" After push_back(6) " <<vec.capacity() <<std::endl;
        // when the size was increased by one(i.e., when 6 was added) then the new array became double the size of the initially initialzied array i.e., the new vector is of size 8 (4*2) and on printing the capacity we get 8
        // vectors capacity grows exponentially
        // this strategy is known as table doubling
        // the new array is differnt from old array
        // the old array is deleted and it's space is freed
        // this is how a vector grows
        // drawbacks
        // expensive reallocation
        // requires contiguous memory
        // lot of construction and destruction
        //
        std::vector<Dog> v(6); // 6 dogs are created with default constructor
        std::cout<<"vec : size = " <<v.size()<< "capacity = " << v.capacity()<<std::endl;

        //let's create another object of the dog class
        std::vector<Dog> vec2; // vec2.capacity==0 vec2.size()==0
        vec2.resize(6); //6 doges created with default constructors
        std::cout<<"vec2.size="<<vec2.size()<<" capacity = " <<vec2.capacity()<<std::endl;

        //Example 3
        std::vector<Dog> vec3;
        vec3.reserve(6); // no Dog's default constructor invoked
        std::cout<<"vec3 .size = " << vec3.size() << " capacity = " <<vec3.capacity()<<std::endl;

        //vector v3 has a size of 0 and a capacity of 6
        //the reserve function increases the capacity of the vector
        //and not the size of the vector
        //no dog's  default constructors will be invoked
        //expensive reallocation happens only when the capacity is full
        //so if we already have the idea how many items the vector will be
        //holding we can reserve that amount of memory for that memor
        //so that we preallocate the memory
        //
        //
        /*
         * Strategy of minimizing reallocation
         * 1) If the maximum number of item is known, reserve(max);
         * 2) If the end of grow is known, reserve as much memory as we can, once all data is inserted, trimm of the rest
         */
        v.shrink_to_fit(); // for trimming off the rest
        return 0;
}
