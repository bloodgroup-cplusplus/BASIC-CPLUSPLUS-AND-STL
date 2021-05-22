#include<deque>
#include<list>
#include<iostream>
#include<algorithm>

int main()
{
	std::deque<int> deq={4,6,7};
	deq.push_front(2);//deq;{2,4,6,7}
	deq.push_back(3);//deq:{2,4,6,7,3}
	//deque has similar interface with vecotr
	std::cout<<deq[1];
	// the list is a double linked list. Fast insert and remove at any place
	std::list<int> mylist={4,3,5};
	mylist.push_bakc(6);//mylist:{5,2,9,6}
	mylist.push_front(4);//mylist{4,52,9,6}
	std::list<int>::iterator itr=std::find(mylist.begin(),mylist.end(),2);//itr->2
	mylist.insert(itr,8);//mylist:{4,5,8,2,9,6}
	//O(1) faster then vector/deque
	itr++; //itr=9;
	mylist.erase(itr);//mylist:{4,8,5,2,6} O(1)
	//fast insert/remove at any place:O(1)
	//slow search 0(size of the list)
	//no random acess, no[] opeartor
	// the list has a splice opeartor which is used to cut a certain range from the list and insert 
	mylist1.splice (itr,mylis2,itr_a,itr_b);//O(1)
	return 0;
}
