#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int n,x0,y0,x,y,i,c=0;
	cin>>n>>x0>>y0;
	double slope=0;

	map<double,int> guns;
	map<double,bool>unique;

	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		if (y==y0)
		slope=INT_MAX;
		else
		slope=((double)(x-x0))/(y-y0);
		if(unique[slope]==false)
		{
			guns[slope]++;
			unique[slope]=true;
		}

	}
	map<double,int> :: iterator it;
	for(it=guns.begin();it!=guns.end();it++)
		c++;
	cout<<c;

}
