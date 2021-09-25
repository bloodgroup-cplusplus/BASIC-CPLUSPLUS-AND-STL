/ union in c++

/// NOTEs;

// 1. Just like structures and classes a union is a user defined data type

// 2. In union, all members share the biggest same memory location.


// This is used to achieve polymorphism in C++.

// Possible usage?

// When we need only one value out of many that time we will use it 

// Get the actual data in parts. (Example: int value, char bytes[4])



#include<iostream>

union myUnion
{
        int x;
        short y;
        char c;


};

union Square
{
        int width;
        int height;
};


int getArea(int width, int height)
{
        return width *height;
}


// similar names for different works 
// similar names for different works of a function
// in union we have only one memory and alll other data members are pointing to it
// use of unions
// if it is having so many members but it is creating the biggest one only
                                                                                                                                                                                         1,1           Top

