#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;

int main()
{
	lli t,i;
	cin>>t;
	while(t--)
	{
		lli n,d,k,i;
		cin>>n>>k>>d;
		vector<lli>vec;
		for(i=0;i<n;i++)

		{
			lli p;
			cin>>p;
			vec.push_back(p);
		}
		lli ans=INT_MAX;
		map<lli,lli>mp;
		lli dis=0;
		for(i=0;i<d;i++)
		{
			if(mp[vec[i]]==0)
				dis++;
			mp[vec[i]]+=1;


		}
		ans=min(ans,dis);
		for(i=d;i<n;i++)
		{
			if(mp[vec[i-d]]==1)
				dis--;
			mp[vec[i-d]]-=1;
			if(mp[vec[i]]==0)
				dis++;
			mp[vec[i]]+=1;
			ans=min(ans,dis);
		}
		cout<<ans<<endl;

	}
}