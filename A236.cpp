#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int c=0,f=0,i,j;
	for(i=97;i<=122;i++)
	{
		c=0;
		for(j=0;j<s.length();j++)
		{
			if(s[j]==(char)i)
			c++;
		}

		if(c>=1)
		f++;
	}

	if(f%2!=0)
	cout<<"IGNORE HIM!";
	else
	cout<<"CHAT WITH HER!";
}
