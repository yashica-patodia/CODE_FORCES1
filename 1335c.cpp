#include<bits/stdc++.h>
using namespace std;
typedef  long long int lli;
int main()
{
	lli t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<lli>vec;
		vec.clear();
		lli cnt[200010]={0};
		cnt[0]=0;
		for(i=0;i<n;i++)
		{
			lli p;
			cin>>p;
			vec.push_back(p);
			cnt[p]++;

		}
		sort(vec.begin(),vec.end());
		lli dis=0,sm=0;

		for(i=0;i<n;i++)
		{
			if(cnt[vec[i]]==1)
				dis++;
			//cout<<dis<<" ";
			if(cnt[vec[i]]>1)
				sm++;
			//cout<<sm<<" ";


		}

		//lli ans=min(dis,sm);
		

		
cout<<ans<<endl;

	}
}