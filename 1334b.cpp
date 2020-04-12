#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int t,n,x;
	lli i;
	cin>>t;
	while(t--)
	{
		lli arr,sum=0,ans=0;
		cin>>n>>x;
		vector<lli>vec;
		for(i=0;i<n;i++)
		{
			cin>>arr;
			vec.push_back(arr);
		}
		sort(vec.begin(),vec.end(),greater<int>());

		for(i=0;i<n;i++)
		{
			sum+=vec[i];
			if(sum>=(x*(i+1)))
				ans=i+1;
		}
	
	cout<<ans<<endl;	
}




			

	
		
}