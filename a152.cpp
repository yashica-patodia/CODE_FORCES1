#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,m,dx,dy,xc,yc,k;
bool isvalid(lli x,lli y);
int main()
{
cin>>n>>m;
cin>>xc>>yc;
cin>>k;
lli c=0;
lli coorx,coory;
while(k--)
{
	lli x,y;
	cin>>x>>y;
	coorx=xc;
	coory=yc;
	for(lli i=max(n,m);i>=1;i/=2)
	{
		while(isvalid(coorx+i*x,coory+i*y))
		{
			coorx+=i*x;
			coory+=i*y;
		}
	}
	if(x!=0)
	c+=(coorx-xc)/x;
	else
	c+=(coory-yc)/y;
	xc=coorx;
	yc=coory;
}
cout<<c;
}



bool isvalid(lli x,lli y)
{
if(x<=n && y<=m && x>=1 && y>=1)
return true;
else
return false;
}
