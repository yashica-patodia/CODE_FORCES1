#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int n,m,x,y,k,ix,iy,i,dx,dy,c=0;
cin>>n>>m;
cin>>x>>y;
n=n-1;
m=m-1;
x=x-1;
y=y-1;
cin>>k;
ix=x;
iy=y;
for(i=1;i<=k;i++)
{
	cin>>dx>>dy;
	do
	{
	ix=ix+dx;
	iy=iy+dy;
	c++;
	}
	while(ix<=n && iy<=m  && ix>=0 && iy>=0);
	ix=ix-dx;
	iy=iy-dy;
c=c-1;
}
cout<<c;
}


