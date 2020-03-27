#include<bits/stdc++.h>
using namespace std;
int main()
{
int i,j,c=0,ans=0;
int s[4];
for(i=0;i<4;i++)
cin>>s[i];
for(i=0;i<3;i++)
{
	long long int k=s[i];
	c=0;
	for(j=i+1;j<4;j++)
	{
		if(k==s[j] && s[j]!=0)
		{
			c++;
			s[j]=0;
		}

	}
	if (c>=1)
	ans+=c;
}
cout<<ans;
}
