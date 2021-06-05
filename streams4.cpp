// the main necessity of IO operation are
// formatting data --stream
// communicating data to external devices --stream buffer
// cout<<35;
// streambuf * pbuf=cout.rdbuf();
// cout is responsible for formatting the data
// cout is responsible for transmitting out 
// ostream myCout(pbuf);
// we have created our own customized transferring channel
// ostream myCout(pbuf);
// myCout<<34;// 34 will be printed out to standard out
// if i wan't to change the format of cout
// myCout.setf(ios::showpos). this will show the positive sign of a number
// myCout.width(20); // right aligned width 20 data
// mycout<<12<<endl; //         +12
// cout<<12<<endl; this just prints 12 only
// thi is useful for temporary changing the format for standard out
// but i don't wan't to change cout because somebody else is using cout
// ofstream of("MyLog.txt") opens for writing
// cout.rebuf(of.rdbuf()); we have assigened of to cout
// cout<<"Hello"<< endl;//My Log.txt has "Hello"
// Redirecting stdout to a logfile
// this is devoid of restoration so to prevent this
// streambuf *origBuf =cout.rdbuf();
// cout.rdbuf(origBuf);
// cout<<"Goodby"<<std::endl; // stdout::Goodby
// another way to access the stream buffer is using the stream buffer iterator
// istreambuf_iterator<char> i(cin); 
// ostreambuf_iterator<char> o(cout);
// these are two stream iterators
// while(*i!='x')
// {
//      *o=*i;
//      ++o;
//      ++i;
// }
//
// this will take everything from input and echo it out to stdout
// using copy 
// copy(istream_iterator<char>(cin),istreambuf_iterator<char>(),ostreambuf_iterator<char>(cout));
// this will do the same thing

#include<iostream>
#include<algorithm>
#include<fstream>
#include<iterator>
int main()
{
        std::cout<<35<<std::endl;
        std::streambuf *pbuf=std::cout.rdbuf();
        std::ostream myCout(pbuf);
        myCout<<35<<std::endl;
        myCout.setf(std::ios::showpos);
        myCout.width(20);
        myCout<<12<<std::endl;
        std::ofstream of("MyLog.txt");
        std::cout.rdbuf(of.rdbuf());
        std::cout<<"Goodbye"<<std::endl;
        std::cout<<"when ever i am writing in the console i am actually writing on  the file"<<std::endl;
        std::streambuf *origBuf= std::cout.rdbuf();
        std::cout.rdbuf(origBuf);
        std::cout<<"Goodbye"<<std::endl;
        std::istreambuf_iterator<char> i(std::cin);
        std::ostreambuf_iterator<char> o(std::cout);
        while(*i!='x')
        {
                *o=*i;
                ++i;
                ++o;
        }
//      std::copy(std::istream_iterator<char>(std::cin),std::istreambuf_iterator<char> (), std::ostreambuf_iterator<char>(std::cout));

        return 0;
}
