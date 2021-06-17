#include<numeric>
#include<ctime>
#include<cmath>
#include<iostream>

int main(int argc, char **argv)
{
        double num3= 10, num4=0;
        try
        {
                if(num4 ==0)

                {
                        throw "division by zero error";
                }

                else
                {
                        printf("%.1f / %.1f = %.1f",num3,num4,(num3/num4));

                }

        }

        catch(const char *exp)
        {
                std::cout<<"Error:"<<exp<<std::endl;
        }
        return 0;
}
