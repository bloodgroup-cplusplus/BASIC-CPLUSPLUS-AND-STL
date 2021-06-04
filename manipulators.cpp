// int main()
// {
//      cout<<"Hello <<endl; //endl='\n' and flush
// what is endl object? build-in data type? function?
// it is actually a function
// the defintion of endl is
// ostream & endl(ostream & sm)//it is called a manipulator
// {
//      sm.put('\n');
//      sm.flush();
//      return sm;
// }
//
// what is this output operator
// output operator is the member function of the stream
// ostream& ostream ::operator<<(ostream & (*fun)(ostream &))
// pointer to a function which has same signature as endl
// and that operator is overloaded
// to take a function like this and a parameters
// ostream & ostream::operator<<(ostream& (*func) (ostream &))
// {
//      return (*func)(*this);
//      it will invoke this function on ths ostream
//      and then reuturn the returned value
// }
//
// end of function has a special name known as manipulator
// cout<< ends;//'\0'
// cout<<flush;
// cin>> ws ; // read and discard white spaces
// cout<<setw(8)//manipulator that sets the width of cout to 8
// cout<<setw(8) <<left<<setfill('_')<<99<<<endl;
// it prints out 99__________(8 times)
// cout<<hex<<showbase<< 14; // this prints out  //0xe
// there are lot of manipulators in c++ standard library
// iomanip
// has more manipulatros
// get_money // put_money for 
//

#include<iostream>

std::ostream & endl(std::ostream &sm)
{
        sm.put('\n');
        sm.flush();
        return sm;
}

int main()
{
        std::cout<<"hello" <<std::endl;
        std::cout<<std::ends;
        std::cin>>std::ws;// read and discard the white spaces
//      std::cout<<getw(8);// manipulator that sets the width of cout to 8
//      std::cout<<getw(8)<<std::left<<std::fill('_')<<99<<std::endl;
        std::cout<<std::hex<<std::showbase<<14<<std::endl;
        return 0;
}
                                                                                                                                                                                                                                                                                                                        
