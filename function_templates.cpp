#include<iostream>
template<typename T>
T add( T a, T b)
{
        return a+b;
}

template<class rettype, class argtype> rettype cast(argtype x)
{
        return (rettype) x;
}


template< typename T>
void print_data(T data)
{
        std::cout<<data<<std::endl;
}

template<typename T1, typename T2>
T2 get_max( T1 a, T2 b)
{
        return a>b? a:b;
}

int main( int argc, char **argv)
{
        double x =add<double> (3.3,3.3);
        std::cout<<x<<std::endl;
        int y= add<double> (3.2,3.2);
        std::cout<<y<<std::endl;

        std::cout<<cast<double> (10.123)<<std::endl;
        print_data(3);
        print_data(2.1);
        print_data('c');
        std::cout<<get_max(1.2,3.4)<<std::endl;
        std::cout<<get_max(1,2.3)<<std::endl;
        return 0;
}
