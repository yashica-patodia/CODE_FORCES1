#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli n,k,i;
	cin>>n>>k;
	vector<lli>vec;
	for(i=0;i<n;i++)
	{
		lli p;
		cin>>p;
		vec.push_back(p);
	}
	deque<lli>dq;
	set<lli>st;
	for(i=0;i<n;i++)
	{
		if(!st.empty() && st.find(vec[i])!=st.end())
		{
			continue;
		}
		if(dq.size()==k)
		{
			lli temp=dq.back();
			dq.pop_back();
			st.erase(temp);

		}
		dq.push_front(vec[i]);
		st.insert(vec[i]);
	}
	cout<<dq.size()<<endl;
	for(auto j:dq)
		cout<<j<<" ";



}