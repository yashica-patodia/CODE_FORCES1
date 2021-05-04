#include<bits/stdc++.h>
using namespace std;
int main()
{
int k,min2,i;
string s;
cin>>s;
int c=0;
for(i=0;i<s.length();i++)
{
	if(i==0)
	{
		 k=s[i]-97;
		 min2=(k<(26-k))? k:26-k;
		c+=min2;
	}
	else
	{
		 k=abs(s[i]-s[i-1]);
		 min2=(k<(26-k))? k:26-k;
		c+=min2;
	}
}
cout<<c;
}
