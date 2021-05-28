/*
 * STL Algorithm Walkthorugh
 * Non-modifying Algorithms
 * count,min and max, compare, linear search,attribute they are the non-modifying algorithms
 * you should be using stl algorithms a lot
 * impressions of algorithms exists in stl
 * we will be using c++ 11 lambda function
 */

#include<algorithm>
#include<vector>
#include<iostream>
#include<tuple>

int main()
{
        std::vector<int> v={2,33333,32,1,22,3343,32,232};

        int n=std::count(v.begin(),v.end(),32);
        // the answer returned is 2 as there are two 32's in the vector v
        std::cout<<"the number of 32's in the vector is  "<<n<<std::endl;
        int m=std::count_if(v.begin(),v.end(),[](int x){return x>10;});

        std::cout<<"the number of integer value greater than 10 in the vector v is  "<<m<<std::endl;

        std::vector<int>::iterator it,it1;

        it=max_element(v.begin()+2,v.end());

        std::cout<< *it<<std::endl;

        return 0;
}
