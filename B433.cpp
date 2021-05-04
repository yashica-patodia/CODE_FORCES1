#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	lli a[n],b[n];
	
	for(i=0;i<n;i++)

	{	
	cin>>a[i];
	b[i]=a[i];
	}
	int m;
	cin>>m;
	lli x[n],y[n];
	x[0]=a[0];
	y[0]=b[0];
	sort(b,b+n);
	for(i=1;i<n;i++)
	{
	x[i]=x[i-1]+a[i];
	y[i]=y[i-1]+b[i];
	}
	
	int k=0;
	for(i=0;i<m;i++)
	{
	int t,l,r;
	cin>>t>>l>>r;
	l--;
	r--;
	if(t==1)
	cout<<x[r]-x[l]+a[l]<<endl;
	else
	cout<<y[r]-y[l]+b[l]<<endl;
	
	}
	
}



