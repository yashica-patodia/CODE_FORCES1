#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,x,crime=0,c=0,i;
cin>>n;
for(i=0;i<n;i++)
{
	cin>>x;
	if(i==0 && x==-1)
	{
		crime++;
		continue;
	}
	if(x>=1)
	c+=x;
	if(x==-1)
	{
		if(c>0)
		c--;
		else
		crime++;
	}
}
cout<<crime;
}
