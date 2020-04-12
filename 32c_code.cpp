#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli n,m,s;
	cin>>n>>m>>s;
	lli hm=max((lli)1,((n-1)/s)+1);
	lli vm=max((lli)1,((m-1)/s)+1);
	int h=(n-1)%s+1;
	int  v=(m-1)%s+1;
	lli ans=hm*vm*h*v;
	cout<<ans;

}