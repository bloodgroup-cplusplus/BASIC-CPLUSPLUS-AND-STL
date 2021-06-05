// string streams doesn't have io channels
// it does't do io operations
// it only does read/ write of string
// it is treating a string as it is treatng a file
// offline data formatting before sending the data for output or before reading
// ss<<89<<"Hex"<< 89<< "oct"<<oct <<89;
// cout<<ss.str()<<endl;
// this will print out 89 Hex :59  Oct:131
// int a,b,c;
// string s1;
// ss>> hex>> a;  // formatted inuputs works token by token. spaces, tabs, and newlines
// 89 is the first token
// a=137
// ss>> s1; // s1 will contain "Hex:"
// ss>> dec>> b; // it will pass the next token which is 89 and it will be passed to b
// ss.ignore(6); next six characters in the stream will be ignored
// ss>> oct>> c; // will pass the next token as the octal number
// there are two classes
// ostringstream --formatted output
// istringstream --formatted input
// they provideing better type safety 
// they make our code even more readable

#include<iostream>
#include<string>
 struct Dog
 {
        int age_;
        std::string name_;
 };

std::ostream & operator <<(std::ostream & sm, const Dog & d){
        sm <<"My name is "<<d.name_<<"  and  my age is "<<d.age_ <<std::endl;
        return sm;
 }
std:: istream & operator >>( std::istream & sm, struct Dog &d)
 {
         sm>> d.age_;
         sm>> d.name_;
        return sm;
 }



 int main()
 {
        struct Dog d{2,"Bob"};// Universal initialization
        std::cin>> d;
        std::cout<<d;
        return 0;

 }
