#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,p,i;
	cin>>n>>k;
	vector<int>vec(n,0);
	for(i=0;i<n;i++)
	{
		cin>>p;
		vec[i]=p;
	}
	int dp[n]={0};
	dp[0]=vec[0];
	int f=0;
	int m=0;
	for(i=1;i<n;i++)
	{
		m=max(m,dp[i-1]);
		if(vec[i]==1)
		{
			if(vec[i-1]==0)
				dp[i]=m;
			else
			dp[i]=1+dp[i-1];
		
		}
		if(vec[i]==0)
		{
			dp[i]=dp[i-1];
			
		}
		

	}
	m=max(m,dp[n-1]);
	
	for(i=0;i<n;i++)
		cout<<dp[i]<<endl;


}