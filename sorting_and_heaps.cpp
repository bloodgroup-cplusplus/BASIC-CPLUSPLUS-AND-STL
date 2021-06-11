#include<algorithm>
#include<vector>
#include<iostream>
bool lsb_less(int x, int y)
{
        return (x%10)<(y%10);
}

bool lessThan10(int i)
{
        return (i<10);
}

int main()
{
        //sorting algorithm requires random access iterators:
        //vector, deque, container array, native array does sorting


        std::vector<int> vec={9,1,10,2,45,3,90,4,9,5,8};

        std::sort(vec.begin(),vec.end()); // this sorts with operator < default
        // new vec= 1,2,3,4,5,8,9,9,10 45,90
        //
        //

        std::sort(vec.begin(),vec.end(),lsb_less); // this sorts with the above function defintion

        // vec =10,90,1,2,3,4,45,5,8,9 9
        //sorts according to the last digit


        //Sometimes we don't need complete sorting.
        //
        //Problem #1:Finding top 5 students according to their test scores
        //this can be solved using partial sort
        //- Partial sort
        //
        std::vector<int>v1={9,60,70,8,45,87,90,69,69,55,7};
        std::partial_sort(v1.begin(),v1.begin()+5,v1.end(),std::greater<int>());
        for(auto x:v1)
        {
                std::cout<<x<<" ";
        }
        //vec =90,87,70,69,69,8,9,45,60,55,7
        //
        //
        std::partial_sort(v1.begin(),v1.begin()+5,v1.end());
        //bottom 5 students will be sorted
        //      7,8,9,45,55,90,60,87,70,69,69


        //Problem#2 :Finding top 5 students according to their score but I don't care their order

        std::vector<int> vag={9,60,70,8,45,87,90,69,69,55,7};
        std::nth_element(vag.begin(),vag.begin()+5,vag.end(),std::greater<int>());
        //vec= 69,87,70,90,69,60,55,45,9,8,7
        //top five students are moved but they are not sorted

        //Problem number 3 :Move the students whose score is less than 10 to the front

        std::vector<int> vmove={9,60,70,8,45,87,90,69,69,55,7};

        std::partition(vmove.begin(),vmove.end(),lessThan10);
        //vec:8,7,9,90,69,60,55,45,70,87,69
        //first group contains the elements which are less than 10
        //second group contains the elements which are greater than 10
        //and neither group is sorted
        // this preserve the original order within each partition
        std::stable_partition(vmove.begin(),vmove.end(),lessThan10);
        // it does the same thing but it preserves the original order of the elements
        // vec 9,8,7,60,70,45,87,90,69,69,55

        //Heap Algorithms
        //
        //Heap
        //1:First element is always the largest
        //2 Add/remove takes O(log(n)) time
        //
        std::vector<int> h_vec={9,1,10,2,45,3,90,4,9,5,8};

        std::make_heap(h_vec.begin(),h_vec.end());

        //vec: 90,45,10,9,8,3,9,4,2,5,1


        //Remove the largest data


        std::pop_heap(h_vec.begin(),h_vec.end());
        //swap h_vec[0] with last item h_vec[size-1]
        //heapify [h_vec.begin(),vec.end()-1)
        //

        h_vec.pop_back(); // remove the last item (the largest one)

        //vec :45,9,10,4,8,3,9,1,2,5
        //add new element
        h_vec.push_back(100);
        std::push_heap(h_vec.begin(),h_vec.end());//heapify the last item
        // vec: 100,45,10,4,9,3,9,1,2,5,8



        //Heap sorting

        std::vecotr<int> h_vec1={9,1,10,2,45,3,90,4,9,5,8};
        std::make_heap(h_vec1.begin(),h_vec1.end());

        std::sort_heap(h_vec1.begin(),h_vec1.end());

        //Note: sort_heap can only work on a heap

        return 0;
}
