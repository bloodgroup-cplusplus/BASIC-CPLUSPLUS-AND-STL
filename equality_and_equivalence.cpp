#include<iostream>
#include<set>
#include<algorithm>
class Lsb_less
{
        public:
                bool operator ()(int x, int y)
                {
                        return (x%10)<(y%10);
                }
};

int main()
{

        std::set<int,Lsb_less> s={21,23,26,27};
        std::set<int,Lsb_less>::iterator itr1,itr2;
        itr1=std::find(s.begin(),s.end(),36);
        itr2=s.find(36);
        std::cout<<*itr1<<std::endl;//this is pointing to end of the set as it didn't find 36
        std::cout<<*itr2<<std::endl;// this is pointing to 26
        // this happens becuase the std::find function doesn't use the functor definition of the class
        // i.e., the definition is created for the container and since std::find is a fixed algorithm of
        // std library is strictly looks for the condition of "==" rather than the class definition
        // wheres s.find() is the function of a class and since it has a functor defintion it looks for the 
        // functor defintion that's the reason why we have different outputs
        /*If the function is using "<" or its like, it's checking equivalence
         * -Typically it's algorithm that works with sorted data, or a member
         *  function of a container with sorted data, such as associative container.
         *
         *  If the function is using operator "==" or its like, its' checking equality 
         *  Typically the data is not required to be sorted
         *
         *
         *Algorithms of equality
         * search
         * find_end
         * find_first_of
         * adjacent_search
         * Algorithms of equivalence:
         * binary_search
         * includes
         * lower_bound
         * upper_bound
         *
         *
         *
         * Summary:
         * When using a function to search or remove certain element, make sure your 
         * understand the difference between equality and equivalence.
         */
}
