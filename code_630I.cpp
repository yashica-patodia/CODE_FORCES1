#include<bits/stdc++.h>
using namespace  std;
typedef long long int lli;
lli bin(int b);
int main()
{
	int n;
	cin>>n;
lli p=bin(n-3);
lli ans=p*(9*n-3);
cout<<ans<<endl;
}
lli bin(int b)
{
	lli a=4;
	lli res=1;
	while(b!=0)
	{
		if(b&1)
			res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
