// say we want to open a file and write more on it
// ofstream of("MyLog.txt");//Opens the file for write, but also clear the content of the file
// so if you just want to open and write in the end of the file
// do ofstream of("Mylog.txt", ofstream::app)// this moves the output pointer to the end of the file
// of<<"Honesty is the best policy."<<endl;
// let's write in the middle of the file
// ofstream of("MyLog.txt",ofstream::in | ofstream::out);
// of.seakp(10,ios::beg) //beg is the beginning of the file
// the above command moves output pointer 10 chars after beginning of the file
// of <<"12345";
// the above characters will overwrite 5 chars that were present in the beginning
// of.seekp(-5,ios::end);//It will move the output pointer 5 chars before end
// of<<"Nothing ventured, nothing gained."<<std::endl;
// of.seekp(-5,ios::cur);//Move the output pointer 5 chars before the current position
// opening the file for read
// ifstream inf("MyLog.txt");
// int i;
// inf>>i;
// this will read one word from the file and pass it as an integer and save it into i
// but we need to know the exact datatype present for our input
// for that we need to handle the error status
// in the fstream the error format is indicated with four bits
// goodbit, badbit, failbit,eofbit
// inf.goodbit();//if this returns true it tells you everything is ok i.e., (goodbit=1)
// inf.bad(); // Non-recoverable error has happend( badbit==1)
// inf.fail();// failed stream operation. (failbit==1 && badbit==1)
// inf.eof(); // End of file(eofbit==1)
// we can use these to query the errors of the bit
// to clear the errors we can use
// inf.clear();// this will clear all the error status
// error function can also be called with a parameter as that will set a new value
// to the error status
// inf.clear(ios::badbit); // this is setting the badbit to 1
// inf.clear(ios::badbit);//sets a new value to the error flag
// inf .clear();// clear all the error status clear(ios::goodbit)
// inf.rdstate();//read the current status flag
// inf.clear(inf.rdstate() & ~ios::failbit);// this will cleaer only the failbit and everything else stay the same
// if(inf) std::cout<<"read successfully"// this is equivalent to iif(!inf.fail())
// if(inf>>i) cout<<"Read successfully"<< input operatior returns refrence to the steram itself
// the above were examples of manual handling of errors 
// we can also handle the errors using exceptions
// to do that we need to inf.exceptions(ios::badbit | ios::failbit);// setting the exeption mask so that when the badbit// or failbit is set to 1 an exception will be thrown
// when badbit or failbit set to one 1, exceptioin of ios::failure will be thrown when
// when eof bit is set to 1 no exception is thrown
// inf.exceptions(ios::goodbit)// no exception will be generated because of steram status
#include<iostream>
#include<fstream>
int main()
{
        //std::ostream of("MyLog.txt");
        std::ofstream of("MyLog.txt",std::ofstream::app); // move output to end
        of<<"Honesty is the best policy"<<std::endl;
        of.seekp(10,std::ios::beg); // move ten steps from the beginning
        of<<"12345";
        of.seekp(-5,std::ios::end); // move the output pointer 5 chars before end
        of<<"Nothing ventured, nothing gained"<<std::endl;
        of.seekp(-5,std::ios::cur);//Move the output pointer 5 chars before the current position
        std::ifstream inf("MyLog.txt");
        std::cout<<"good bit returns "<<inf.goodbit<<std::endl;
        std::cout<<"bad bit reutrns "<<inf.badbit<<std::endl;
        std::cout<<"0/1 0 for not failed bit operation and 1 for failed bit operation " <<inf.failbit<<std::endl;
        std::cout<<"0/1 0 for not end of file 1 for end of file  "<<inf.eof()<<std::endl;
        inf.clear();//clear all error status
        inf.clear(std::ios::badbit);// this sets badbit to 1
        inf.clear(std::ios::badbit);
        int i;
        inf.rdstate();//read the current status flag
        inf.clear();// clear all the error statu
        inf.rdstate();// read the current status flag
        if(inf)
        {
                std::cout<<"REad successfully"<<std::endl; // this is equivalent to (if !inf.fail())
        }
        if(inf>>i)
        {
                std::cout<<"Read successfully"<<std::endl;// input operator returns refrence to the stream itself
        }
        return 0;
}
