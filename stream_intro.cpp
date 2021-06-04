// streams is a input/output library
// cout<<"HELLO"<<endl will output stream of hello to standard out
// cout is standard out 
// cout is a global object of ostream which lives in std namespace
// ostream is a typedef of basic_ostream<char> ostream)
// what is the leftshit operator
// << is a member function of ostream
// it has signature like this
// <<:ostream & ostream::operator<<(string v);
// endl; is a "\n"+ a flush operation
// cout is a ostream which is a type of a stream
// what is a stream
// stream is a serial IO interface which handles the IO data one by one
// Serial IO interface to external devices(file, stdin/stdout, network, etc)
// string s("Hello")
// we can randomly access any character inside the string
// s[3]='t':// this is a random access
// but cout[3]="t"// this is an error
// file stream provides serial operatoin interface
// examples of filestream
// ofstream of("MyLog.txt")//this will open the file for write. if that does not exists it creates a new file for wirete/
// of<<"experience is the mother of wisdom"<<std::endl;
// left shift is an overloaded member function which takes stream as the parameter
// << is overloaded for all fundamental datatypes
// of<<234<<endl;//writes integer into a file
// of<<2.3<<endl;//writes float into a file
// of<<bitset<8>(14) endl; //writes 00001110 into the file
// of<<complex<int>(2,3)<<endl;//writes (2,3) into the file
// we can exchange the data conviniently we do not need to open or close the file
// as long as we limit the code into certain scope 
// the file is open when the ofstream object is constructed
// it is closed when the ofstream goes out or is closed
// and is destructed
// so it is a typical RAII technique
// what is the advantage of using the stream class
// io opeation contains two steps
// formatting the data <------------> communicating the data with external devices
// the above two steps
// the stream class provides you with the common api i.e, if you want to read a file, a stdin/stdout, a network, etc
// you all use the same api to format the data
// this demonstrates an important software engineering principle
// low coupling 
// one module handles the formatting of the data and another module handles the communicating of the data
// and these two modules are covered from each other as much as possible.
// low coupling promotes resuablility
// the final code 


#include<iostream>
#include<fstream>
#include<bitset>
#include<complex>

int main()
{
        std::ofstream of("MyLog.txt");
        of<<"Experience is the mother of wisdom"<<std::endl;
        of<<234<<std::endl;
        of<<2.3<<std::endl;
        of<<std::bitset<8>(14)<<std::endl;
        of<<std::complex<int>(2,3)<<std::endl;
        return 0;
}
