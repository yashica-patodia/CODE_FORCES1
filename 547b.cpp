#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	lli n;
	lli i,j;
	cin>>n;
	vector<lli>vec;
	for(i=0;i<n;i++)
	{
		lli p;
		cin>>p;
		vec.push_back(p);
	}
	deque<lli>dq;
	 for(j=1;j<=n;j++)
	 {
	
		dq.clear();
		lli ans=0;
	for(i=0;i<j;i++)
	{
		if(!dq.empty())
		{
			while(!dq.empty() && vec[dq.back()]>=vec[i])
			{
				//cout<<dq.front()<<" ";
				dq.pop_back();

			}
		}
		//cout<<i<<" ";
		dq.push_back(i);
		//cout<<dq.front()<<" ";
	}
	//lli ans=0;
	for(i=j;i<n;i++)
	{
		//cout<<vec[dq.front()]<<" ";
		ans=max(ans,vec[dq.front()]);
		//cout<<ans<<endl;
		while(!dq.empty() &&  dq.front()<(i+1-j))
			dq.pop_front();
		while(!dq.empty() && vec[dq.back()]>=vec[i] )
			dq.pop_back();
		dq.push_back(i);
	}

cout<<max(ans,vec[dq.front()])<<" ";
}
}