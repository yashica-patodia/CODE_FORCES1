#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli t,a,b,c,d;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		lli x=b,y=c,z=d;
		while(x>=a && y>=b && z>=c)
		{
			if(x+y>z  && y+z>x && x+z>y)
			{
				cout<<x<<" "<<y<<" "<<z<<endl;
				break;
			}
			if(x+y<=z && x+z<=y)
				x--;
			if(x+y<=z && y+z<=x)
				y--;
			if(y+z<=x && x+z<=y)
				z--;

		}
	}
}