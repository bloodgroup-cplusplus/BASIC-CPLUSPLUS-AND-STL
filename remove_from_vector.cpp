#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
template<class T>

void print(T t, std::string msg)
{
        std::cout<<msg<<"{";
        for(typename T::iterator it=t.begin();it!=t.end();it++)
        {
                std::cout<<*it<<",";

        }

        std::cout<<"}"<<std::endl;
}




int main()
{
        std::vector<int> c= {1,4,6,1,1,1,1,12,18,16}; // remove 1's
        print(c,"original:");
        // for removing the elements of a vector there is a remove in algorithm class of stl 
        // but it goood to use the member function of the datatype itself if it is available.
        //we also can use the erase funciton to erase the element of the vector
        //for(std::vector<int>::iterator itr= c.begin(); itr!=c.end();)
        //{
        //      if(*itr==1)
        //      {
        //              itr=c.erase(itr);
        //      }

        //      else
        //      {
        //              itr++;
        //      }
        //}

        // the time complexity of this code however is O(n*m
        // this code can get the job done)
//      print(c,"After erase () :");
        // but it causes shifiting of data in vector and it causes increase in complexity
        // if size of vector =n and number of items m then the time complexity =O(m*n);
        auto itr= std::remove(c.begin(),c.end(),1); // complexity :o(n)
        //algorithms functions have no idea about the container they only know the data via the iterator
        //so the algorithm function remove has no idea whether the data is stored on a dynamic array or a
        //a binary tree or a hash table that is why it is impossible for algo function remvoe to remvoe itmes from the coontainers
        //so inorder to keep track of the iterator we keep an extra iterator
        c.erase(itr,c.end());
        print(c,"Ater remove () :");
        std::cout<<"capacity ():"<<c.capacity()<<std::endl;
        // c is still occupying the memory so we can use shrink to fit
        c.shrink_to_fit();
        std::cout<<"capacity():"<<c.capacity()<<std::endl;

        return 0;
}
