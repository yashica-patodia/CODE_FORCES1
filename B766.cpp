#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y,z,f=0,i;
	cin>>n;
	int *a;
	a=new int[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(i=0;i<=n-3;i++)
	{
		x=a[i];
		y=a[i+1];
		z=a[i+2];
		if((x+y)>z && (x+z)>y && (y+z)>x)
		{
			f=1;
			cout<<"YES";
			break;
		}
	}
	if(f==0)
	cout<<"NO";
}
