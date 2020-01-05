#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,b,d,i,a,s=0,c=0;
cin>>n>>b>>d;
for(i=0;i<n;i++)
{
	cin>>a;
	if(a<=b)
	s+=a;
	if(s>d)
	{
		c++;
		s=0;
	}
}
cout<<c;
}
