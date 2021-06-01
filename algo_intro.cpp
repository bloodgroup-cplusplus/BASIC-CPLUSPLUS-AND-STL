/*
 * STL Algorithm Walkthorugh
 * Non-modifying Algorithms
 * count,min and max, compare, linear search,attribute they are the non-modifying algorithms
 * you should be using stl algorithms a lot
 * impressions of algorithms exists in stl
 * we will be using c++ 11 lambda function
 */

#include<vector>
#include<iostream>
#include<tuple>
#include<utility>

int main()
{
        std::vector<int> v={2,33333,32,1,22,3343,32,232};

        int n=std::count(v.begin(),v.end(),32);
        // the answer returned is 2 as there are two 32's in the vector v
        std::cout<<"the number of 32's in the vector is  "<<n<<std::endl;
        int m=std::count_if(v.begin(),v.end(),[](int x){return x>10;});

        std::cout<<"the number of integer value greater than 10 in the vector v is  "<<m<<std::endl;

        std::vector<int>::iterator it,it1;
        std::pair<std::vector<int>::iterator,std::vector<int>::iterator>mnmx;
        it=std::max_element(v.begin()+2,v.end());
        std::cout<<"the maximum element starting from second index to the end of the vector is"<<std::endl;
        std::cout<< *it<<std::endl;
        it1=std::max_element(v.begin(),v.end(),[](int x, int y){return (x%10)<(y%10);});
        std::cout<<"This is an example where the iterator is being used to describe our own definition for sorting"<<std::endl;
        std::cout<<*it1<<std::endl;
        //Most algorithms have a simple have a simple form and a generalized form
        it=std::min_element(v.begin(),v.end());
        std::cout<<"the min element of the given vector is"<<std::endl;
        std::cout<<*it<<std::endl;
        mnmx=std::minmax_element(v.begin(),v.end(),[](int x, int y){return (x%10)<(y%10);});
        //returns a pair, which contains first of min and last of max
        std::cout<<"the min value is   "<<*mnmx.first<<"the max value is  "<<*mnmx.second<<std::endl;

        //linear searching (when data is not sorted)
        //returns first match
        it=std::find(v.begin(),v.end(),32);
        std::cout<<*it<<std::endl;

        it=std::find_if(v.begin(),v.end(),[](int x){return x>80;});
        std::cout<<"the first value in vector greater than 80is  "<<*it<<std::endl;
        it =std::find_if_not(v.begin(),v.end(),[](int x){return x>80;});
        std::cout<<"the first value in vector which is not greater than 80 is "<< * it <<std::endl;

        //search for consecitve x times whose value is y
        //itr=std::search_n(v.begin(),v.end(),x,y);
        it=std::search_n(v.begin(),v.end(),2,32);
        std::cout<<"The consecutive  " << 2<< "  elements whose value is 32 is  "<<*it<<std::endl;


}
