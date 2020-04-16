#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
	lli n,m;
	cin>>n>>m;
	if(m>=n)
	{
		cout<<n<<endl;
	}
	else
	{
		lli lb=0,ub=2e9,mm,ans;
		while(lb<=ub)
		{
			mm=lb+(ub-lb)/2;
			lli val=(mm)*(mm+1)/2;
			if(n-val<=m)
				{	ans=mm;
				ub=mm-1;
			}
			else
				lb=mm+1;
		}
		cout<<ans+m<<endl;

	}
}