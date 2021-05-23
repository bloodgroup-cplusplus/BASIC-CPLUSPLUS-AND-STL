#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<forward_list>
int main()
{
        std::vector<int>v ={343,2,3,4,5,6,4};
        std::vector<int>::iterator itr;
        itr=v.begin();// Initial value of iterator is 0
        std::cout<<"I am a vector iterator intially having value "<< *itr<<" which is the value of the first element of a vector v"<<std::endl;
        itr=itr+5;// advance itr by 5
        std::cout<<"Now i am incremented by 5"<<std::endl;
        itr=itr-4;
        std::cout<<"Now i am decremented by 4"<<std::endl;
        std::vector<int> v1={3,4,4,345,34534,323};
        std::vector<int>::iterator itr2;
        itr2=v1.begin();
        std::cout<<"I am v2 which is an iterator of second vector which has value "<<*itr2<<" which is the value of first element of another vector"<<std::endl;
        itr2=itr-1;
        if(itr2>itr)
        {
                ++itr;//faster than itr++
                --itr;
        }

//Bidirectional Iterator:list ,set/multiset,map/multimap  we can add substract but cannot compare two bireactional iterator
// the list data structre of stl library has a bidirectional iterator
        std::list<int> li={1,3,4,5,6,7,8};
        std::list<int>::iterator listr;
        listr=li.begin();
        std::cout<<"I am a list iterator with value"<<*listr<<std::endl;
        ++listr;
        std::cout<<" I was incremented once and now i point to the  value  "<<std::endl;
        std::cout<<*listr<<std::endl;
        std::cout<<"I was decremented once and now i point to the value"<<std::endl;
        --listr;
        std::cout<<*listr<<std::endl;

//Forward iterator cannot be moved in backward direaction or cannot be compared it can only be moved in a
//forward direction
        std::forward_list<int>flist={1,3,5,3,56};
        std::forward_list<int>::iterator flistr;
        flistr=flist.begin();
        ++flistr;
        std::cout<<"I am a forward list iterator i initally had value 1 and was incremented by one i now hold the value"<<std::endl;
        std::cout<<*flistr<<std::endl;

//Unordered containers provide "at least" forward iterators.
//But they have the option to provide bidireactional iterator
//


//4 Input iterator: read and process value while iterationg forward.
//
        int x=*itr;
// 5. Output Iterator.Output values while iterating forward. Both input and output iterator are
//
//
// Every container has a iterator and a const_iterator

        std::set<int>::iterator setitr;
        std::set<int>::const_iterator citr;// Read only access to container elements
        std::cout<<"I am a set iterator and i am iterating the values of a set"<<std::endl;
        std::set<int> myset={2,4,5,1,9};
        for(citr=myset.begin();citr!=myset.end();++citr)
        {
                std::cout<<*citr<<std::endl;
        }


        //for_each(myset.cbegin(),myset.cend(),MyFunction);//only in c++11
        // c.begin and c.end provide convinent access to the alogrith for_each Myfunction can only read and cannot modify elem in 
        //

        //Iterator Functions:
        advance(itr,4);//Move itr forward 5 spots . itr+=5
        //distance(itr1,itr2);// Measure the distance between two itertors.
        std::cout<<"We two are the initial vector iterators with itr applied to the function advance(itr,4) and distance(itr2,itr) between us   is calcuated in the second print statement"<<std::endl;
        std::cout<<*itr<<std::endl;
        std::cout<<distance(itr2,itr)<<std::endl;
        return 0;
}

