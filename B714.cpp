#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n;
lli *arr;

int  main()
{
int i,k,p=0,c=0,dis=0;
cin>>n;
arr=new lli [n];
for(i=0;i<n;i++)
cin>>arr[i];
lli distinct[n];

for(lli j=0;j<=10e9;j++)
{
	c=0;
	for( k=0;k<n;k++)
	{
		if(j==arr[k])
		c+=1;
	}
	if(c==1)
	{
		distinct[p++]=j;
		dis++;
	}
}
if(dis==1)
cout<<"YES";
 else if(dis==2)
cout<<"YES";
else if(dis==3)
{
if(2*distinct[1]==(distinct[0]+distinct[2]))
cout<<"YES";

}
else if(dis>=4)
cout<<"NO";
}

