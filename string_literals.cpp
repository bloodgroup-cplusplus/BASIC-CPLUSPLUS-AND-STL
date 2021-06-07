#include<iostream>

int main()
{
        char * a= u8"string";// to define a UTF-8 string
        char16_t* b= u"string";// to define a UTF-16 string.
        char32_t* c=U"string"; // to define a UTF-32 string.
        char * d= R"(string)"; // define a raw string;
        std::cout<<a<<std::endl;
        std::cout<<b<<std::endl;
        std::cout<<c<<std::endl;
        std::cout<<d<<std::endl;
        return 0;
}                
