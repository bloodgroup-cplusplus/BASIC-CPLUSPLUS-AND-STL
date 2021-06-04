//the main purpose to stream class is to format the data
// cout<<34<endl;//prints 34
// cout.sef(std::ios::oct, ios::basefield) ; sets stdout to be octal
// cout<<34 now prints out 32
// cout.setf(ios::showbase); 
// cout<<34;// it prints out 042( it shows the base)
// cout<<34;// it prints 0x22( it is the hexadecimal number)
// cout.unsetf(std::ios::showbase);
// cout<<34; // this prints out 22 and hides 0x i.e., hides the base info
// cout.setf(ios::dec, ios::basefield);// changes back to decimal
// cout.width(10); //output width is 10 chars
// cout<<26<<endl;// this is left aligned right 10 chars
// cout.setf(ios::left, ios::adjustfield); //26 adjusting the alignment
// Floating point value
// cout.setf(ios::scientific, ios::floatfield);
// cout<<340.1<<endl;// this prints 3.410100e+002
// cout.setf(ios::fixed, ios::floatfield);
// cout<<340.1<<endl;// this prints 340.10000
// cout.precision(3);
// this prints out <<340.1<< endl;// this prints 340.100
// formatting for the input
// int i;
// cin.setf(ios::hex, ios::basefield)
// cin>> i;
// at this point if we enter  12 in input we get i=18 in hex
// cout.flags();returns the information about the current settings
// ios::fmtflags f=cout.flags();
// if this function has a parameter cout.flags(ios::oct| ios::showbase);
// Member functions of stream class that handle unformatted io
// which means it will handle the input output data as raw text
// input
// ifstream inf("MyLog.txt");
// char buf[80];
// inf.get(buf,80);//this will read up to 80 chars and save them into buff
// inf.getlne(buf, 80);// read up to 80 chars until \n is encounterd
// inf.read(buf,20); // read 20 chars
// inf.ignore(3);// ignore next three charactes in the stream
// inf.peek(); top three charcter
// inf.unget();// returns a char back to the stream
// inf.get() we will get the character we have gotten back last character back tot the stream
// put back differnt character back to the stream
// inf.gcount();// return the number of chars being read by last unformatted read
// output
// ofstream of("MyLog.txt");
// of.put('c') put one character to the stream
// of.write(buf,6);//write first 6 chars of buf into the stream

#include<iostream>
#include<fstream>
int main()
{
        std::cout<<34<<std::endl;
        std::cout.setf(std::ios::oct, std::ios::basefield);
        std::cout<<34<<std::endl;
        //std::cout(std::ios::showbase);
        std::cout<<34<<std::endl;
        std::cout.unsetf(std::ios::showbase);
        std::cout<<34<<std::endl;
        std::cout.setf(std::ios::dec,std::ios::showbase);
        std::cout<<34<<std::endl;
        std::cout.width(10);
        std::cout<<26<<std::endl;
        std::cout.setf(std::ios::scientific,std::ios::floatfield);
        std::cout<<340.1<<std::endl;
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout<<340.1<<std::endl;
        std::cout.precision(3);
        int i;
        std::cin.setf(std::ios::hex, std::ios::basefield);
        std::cin>>i;
        std::cout.flags();
        std::ifstream inf("MyLog.txt");
        char buf[80];
        inf.get(buf,80);
        inf.getline(buf,80);
        inf.read(buf,20);
        inf.ignore(3);
        inf.peek();
        inf.unget();
        inf.gcount();
        std::ofstream of("MyLog.txt");
        of.put('c');
        of.write(buf,6);
        return 0;
}
