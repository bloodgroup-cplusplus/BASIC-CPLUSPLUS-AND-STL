#include<iostream>
#include<set>
int main()
{
	 int n;
	std::multiset<int> m_set (n);
	for(int i=0;i<n;++i)
	{
		 int x ;
		cin>>x;
		m_set.insert(x);
	}
	
	return 0;
}

		
