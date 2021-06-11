
#include<iterator>
#include<algorithm>
int main()
{
        // two ways to declare a reverse iterator one is a typedef of other
        std::reverse_iterator<std::vector<int>::iterator> ritr;
        std::vector<int>::reverse_iterator ritr1;

        // traversing with reverse iterator
        std::vector<int> vec={4,5,6,7};
        std::reverse_iterator<std::vector<int>::iterator> ritr3;
        for(ritr3=vec.rbegin();ritr3!=vec.rend();ritr3++)
        {
                std::cout<<*ritr3<<std::endl; // prints 7 6 5 4
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
        //reverse iterator can be converted to regular iterator.but the reverse is not possible
        std::vector<int>::iterator it4;
        std::vector<int>::reverse_iterator it5;
//      it4=std::vector<int>::iterator(it5); // compilation error
        it4=ritr.base();
        //the base function will return the current iterator
        // let's consider  a vector of integer 12345
        std::vector<int> v={1,2,3,4,5};
        std::reverse_iterator<std::vector<int>::iterator> itr6= std::find(v.rbegin(),v.rend(),3);
        std::cout<<(*itr6)<<std::endl; // 3
        std::vector<int>::iterator itr7=itr6.base();
        std::cout<<(*itr7)<<std::endl;
        // the above statemnt prints 4 when ritr is converted to itr
        // the reverse iterator and iterator can get converted to one another but they don't end up pointing
        // to the same thing
        // vec.begin() points to the first item 
        // vec.end() points to the last_item +1th (outside the vector)
        // vec.rbegin() points out to the last_item;
        // vec.rend() points out the the -1( outside the vector before zeroth item)
        // the begins are in position but the ends are outside
        // if itr is pointing to n then ritr is pointing to n+1
        std::vector<int>vec1={1,2,3,4,5};
        std::reverse_iterator<std::vector<int> ::iterator> ritr9;
        ritr=std::find(vec1.rbegin(),vec1.rend(),3);

        // Inserting 
        std::cout<<"here"<<std::endl;

        vec1.insert(ritr9.base(),9); // vec{1,2,3,9,4,5}
//      vec.insert(ritr.base() ,9); // vec{1,2,3,9,4,5}
        // the above two operations have the same effect


//      vec={1,2,3,4,5};

        ritr9=std::find(vec1.rbegin(),vec1.rend(),3);

        //Erasing
        //vec1.erase(ritr9.base());                     

        return 0;
}

