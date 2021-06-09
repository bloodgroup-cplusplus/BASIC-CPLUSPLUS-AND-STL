#include<iostream>

#include<vector>
class BigArray
{
        std::vector<int> v; // huge vector
        mutable int accessCounter;// this shows how many times the huge vector has been accessed
        int *v2; // another int array
        public:
                int getItem( int index) const

                {


                        accessCounter++;// this step is against the compiler
                        // the compiler mantains the rule of bitwise constness
                        // as long as the function has made changed
                        // so there occurs a conflict between the concept of constness by the standards of c++ and by the standards of compiler
                        // how can we solve this conflict.
                        // we can make a member of access counter a mutable
                        //
                        // the other solution could be to const_cast the object
                        const_cast<BigArray*>(this)->accessCounter++;
                        return v[index];//it just returns the top value
                }


                // we can also call make a const function which doesn't change any contents of the class directly


                void setV2Item(int index, int x) const
                {
                        *(v2+index)=x;
                }



};;


int main()
{
        BigArray b;

        // use mutable members to implement logical constness
        //const int * const fun(const int *const & p) const;
        return 0;
}
