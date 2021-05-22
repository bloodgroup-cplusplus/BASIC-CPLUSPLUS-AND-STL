//vectors
#include<iostream>
#include<vector>
//vectors are sequence containers and are dynamci arrays which grows in one direction

int main()
{
  std::vector<int> vec;//vec.size()=0;(initially vector size is zero)
  vec.push_back(54);//push back is a function to insert data into the vector
  vec.push_back(343);
  vec.push_back(8);
  
  for(int i=0;i<vec.size();++i)
  {
      std::cout<<vec[i]<<" ";
  }
  
  //Given below is the universal way of iterating a container any container
  //for(std::container_name<type>::iterator iterator_name=container.begin();iterator_name!=container.end();++iter)
  //{
       // std::cout<<*iter<<" ";
  //}
  
   // following the same rules for vector
   for(std::vector<int>::iterator itr=vec.begin();iter!=vec.end();++itr)
   {
        std::cout<<*itr<<" ";
   }
   
   for(auto it:vec)
   {
        std::cout<<it<<std::endl;
    }
    
    //Vector is dynamically allocated contiguous array in memory
    int *p=&vec[0];
    if(vec.empty())
    {
            std::cout<<"The vecotr is empty"<<std::endl;
    }
    
    std::cout<<vec.size()<<std::endl;//prints the size of the vector
    std::vector<int>vec2(vec);//copy constructor;vec2;{4,1,9}
    vec.clear();//Remove all items in vec; vec.szie()==0
    vec2.swap(vec);//vec2 becomes empty,and vec has 3 items;
    
}
