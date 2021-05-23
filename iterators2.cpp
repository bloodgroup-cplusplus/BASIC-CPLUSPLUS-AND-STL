*Iterator Adaptor(Predefined iterator)
 * -A speical, more powerful iterator
 *  1. Insert iterator
 *  2. Stream iterator
 *  3. Reverse iterator
 *  4. Move iterator (C++11)
 */

// four kind of iterator adaptor

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
int main()
{
        //Let's see how to use an insert iterator
        std::vector<int> vec1={4,5};
        std::vector<int> vec2={12,14,16,18};
        //find 16 in vec1 and store it in it
        std::vector<int>::iterator it=std::find(vec2.begin(),vec2.end(),16);
        //insert_iterator vec2,it
        std::insert_iterator<std::vector<int>> i_itr(vec2,it);
        //As a result everything in vec1 is inserted before 16
        std::copy(vec1.begin(),vec1.end(),i_itr);//source destination i_itr;
        //vec2:{12,14,4,5,16,18};
        //other insert iterators include back_insert_iterator, front_insert_iterator
        // 2. Stream Iteartor
        //It is used to iterate through a data to and from a stream

        std::vector<std::string> vec4;
        std::copy(std::istream_iterator<std::string> (std::cin),std::istream_iterator<std::string>(),std::back_inserter(vec4));
        std::copy(vec4.begin(),vec4.end(),std::ostream_iterator<std::string>(std::cout," "));

        //combine the above two statements into one statement
        copy(std::istream_iterator<std::string>(std::cin),std::istream_iterator<std::string>(),std::ostream_iterator<std::string>(std::cout," "));

        // Reverse iterator is to traverse a container in reversed order
        std::vector<int> vec={4,5,6,7};
        std::reverse_iterator<std::vector<int>::iterator>ritr;
        for(ritr=vec.rbegin();ritr!=vec.rend();ritr++)
        {
                std::cout<<*ritr<<std::endl;
        }
        return 0;
}


