
// question: what is the difference between shallow and deep copy?
#include<iostream>
#include<iostream>

class Base
{
        int * _ptr;
        int _val;

        pubilc:
                Base(): _ptr{new int (0)}, _val {0}{}
                Base(const Base & rhs)
                {
                        _ptr = new int;
                        *_ptr = *rhs._ptr;
                        _val = rhs. _val;

                }

                void setPtr(int ptr) {*_ptr = ptr ;}
                void setVal(int val ) { _val = val;}
                int getPtr() {return *_ptr;}
                int getVal() {return _val;}


};


int main()
{
        Base b1;
        b1.setPtr(10);
        b1.setVal(15);
        Base b2 =b1;
        b2.setPtr(50);
        std::cout<<"b1 prt: " <<b1.getPtr() << std::endl;
        std::cout<< "b1 val : " << b1.getVAl() << std::endl;
        std::cout<< "b2 ptr: " << b2.getPtr() << std::endl;
        return 0;
}

~                                                                                             
~                                                                                             
~                               
