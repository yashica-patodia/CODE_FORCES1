#include<bits/stdc++.h>
using namespace std;
int dp[300010]={0};
int n,k;
vector<int>vec;
int ch(int k2);
void solve(int k2);

int main()
{
	int i,j,k2=0;
	cin>>n>>k;
	
	for(i=0;i<n;i++)
	{
		int p;
		cin>>p;
		vec.push_back(p);
	}

	
	if(vec[0]==0)
		dp[0]=1;
	else
		dp[0]=0;
	for(i=1;i<n;i++)
	{
		if(vec[i]==0)
		dp[i]=dp[i-1]+1;
	else
		dp[i]=dp[i-1];

	}
	if(k==0 && n==1)
	{
		cout<<!dp[0]<<endl;
		cout<<vec[0]<<endl;
	}
	
// 	while(i<n)
// {
// 	j=i;
// 	while( j<n)
// 	{
// 		if(i>=1)
// 			 k2=dp[j]-dp[i-1];
// 		else
// 			 k2=dp[j];
// 		if(k2<=k)
// 		{
// 			if(j-i+1>mx)
// 			{
// 				mx=j-i+1;
// 				i1=i;
// 				i2=j;
// 			}
// 		}
// 		j++;

// 	}
// 	i++;
// }
	else
	{
	int lb=0,ub=n+1,mm;
	while(lb<ub-1)
	{
		mm=lb+(ub-lb)/2;
		if(ch(mm))
			lb=mm;
		else
			ub=mm;
		//cout<<lb<<" "<<ub<<" "<<ch(mm)<<endl;
	}
	cout<<lb<<endl;
	solve(lb);
}

}
int ch(int k2)
{
	int i,sum=0;
	for(i=0;i<=n-k2;i++)
	{
		if(i==0)
			sum=dp[k2+i-1];
		else
			sum=dp[k2+i-1]-dp[i-1];
		if(sum<=k)
		{
			return 1;
		}

	}
	return 0;

}
void solve(int k2)
{
	int i,i1,i2,sum=0;
	for(i=0;i<=n-k2;i++)
	{
		if(i==0)
			sum=dp[k2+i-1];
		else
			sum=dp[k2+i-1]-dp[i-1];
		if(sum<=k)
		{
			i1=i;
			i2=k2+i-1;
			break;
		}
	}
	for(i=i1;i<=i2;i++)
		vec[i]=1;
	for(i=0;i<n;i++)
		cout<<vec[i]<<" ";
}