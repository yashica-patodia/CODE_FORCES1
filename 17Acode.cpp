#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int main()
{
	int n=1000;
	int i,j;
	vector<bool>prime(n+5,true);
	prime[0]=false;
	prime[1]=false;
	for( i=2;i<=n;i++)
	{
		if(prime[i])
		{
			for( j=i*i;j<=n;j+=i)
				prime[j]=false;
		}
	}
	vector<int>p;
	for(i=2;i<=n;i++)
		if(prime[i])
			p.push_back(i);

	int num,k;
	cin>>num>>k;
	// for(i=5;i<=num;i+=2)
	// {
	// int	index=i-1;


	// }
	// for(i=0;i<p.size();i++)
	// 	cout<<p[i]<<endl;
	lli count=0;
	for(i=0;p[i]<=num && i<p.size();i++)
	{
		lli val=p[i]-1;
		for(j=0;p[j]<(val/2);j++)
		{
			if(p[j]+p[j+1]==val)
			{
			count++;
			break;
			}
		}

	}
	// cout<<count<<endl;
	if(count>=k)
		cout<<"YES";
	else
		cout<<"NO";

}