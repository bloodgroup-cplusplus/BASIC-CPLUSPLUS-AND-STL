#include<iostream>
class dog
{
        public:
                int age;// third choice for compilers
                dog(int a){age=a;}//second choice for compilers
                dog(const std::initializer_list<int> & vec)//first choice for compilers 
                {
                        age =*(vec.begin());
                }

};

int main()
{
        dog d1 {3};
        return 0;
}
