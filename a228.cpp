#include<bits/stdc++.h>
using namespace std;
int main()
{
int s[4];
int ans=0;
 long long int i,j,c;
 long long int k=10e9;
for(i=0;i<4;i++)
cin>>s[i];
for(i=1;i<=k;i++)
{
	c=0;
	for(j=0;j<4;j++)
	{
		if(i==s[j])
		c++;
	cout<<c<<endl;
	}
	if(c>1)
	ans+=c-1;
	cout<<ans<<endl;
}
cout<<ans;
//cout<<k;

}


