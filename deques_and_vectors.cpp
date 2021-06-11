#include<deque>
#include<iostream>

// deque is  a one single giant array 
// if that array runs out of space the deque reallocates another size of similar array
// everytime the space runs out it allocates  a new array (either on front or on back depending on the place where space ran out)
//it goes linearly and not exponentially
//deque has no reallocation
//deque has no reserve() and capacity()
//slightly slower than vector
// due to more complex data structure
// locality (since it is a doubly ended linklist)
// modern compilers puts the data of deque together
/* Element type:
 * - when the elements are not of a trivial type(build-in data  type), deque is not much less efficient than vector(due to performance costs)
 *
 *  Memory Availabilty
 *  vector requires data to reside in contigious memory chunk and sometimes when vecotr becomes bigger
 *  allocating large memory chunk becomes bigger due to embedded system and limitided size
 *  memory flagmentation
 *  if the allocation of large contigious memory is problem use deque
 *
 *  Frequency of unpredictable growth
 *   
 *
 *
 *   Invalidation of pointers/refrences/iterators because of growth
 *   vector<int> vec={2,3,4,5};
 *   int *p=&vec[3];
 *   vec.push_back(6);
 *   cout<<*p<<endl; // this results in undefined behaviour as the vec gets reallocated and reallocation invalidates all the pointers
 *   that was previously pointing to it ( any pointers/refrences/iterators will be invalidataed)
 *
 *   however for deque the result is ok
 *   for deque as long as you are growing the deque the pointers will not be invaldiatad
 *   the pointers will be invalidated 
 *
 *  also if the large chucnk of data is present and the growth frequency is unpredictable
 *
 *
 *  vector<int> vec;
 *  for(int x=0;x<1025;++x)
 *  {
 *      vec.push_back(x): // 11 reallocations performeed (growth ratio=2)
 *
 *  to prevent this we need to reserve
 *
 *  deque has no realloction
 *
 *
 *vector has a unique function = poratl to C

 * vector<int> vec={2,3,4,5}
 * void c_function( const int * arr, int size)
 * c_fun(&vec[0],vec.size());
 *
 * we can pass the element directly as a refrence to c function
 * for other stl containers we need to first convert them into a vector and then pass it
 * exception of vector<bool> vec;
 * vector of bool is optimized so that each value is represented by one bit 
 * vector<bool> vec={true, ture, false, true}
 * cpp_fun(&vec[0], vec.size(()); // vec[0] is not a bool pointer
 * c doesn't have a bool
 *
 *
 *Summary
 * frequent push_front() -use deque
 * build-in data type =vector
 * not build in data type =deque
 * contigious memory= deque
 * unpredictable growht=deque
 * ponter integrity=deque
 * passed to c function vector
 *
 *
 *
 *
