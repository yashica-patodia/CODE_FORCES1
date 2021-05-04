#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int i,k,f=0;
	transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
	transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
	//if(lexicographical_compare(s1.begin,s1.end(),s2.begin(),s2.end())
	//k=-1
	for(i=0;i<s1.length();i++)
	{
		int k=(int)s1[i]-(int)s2[i];
		if(k>0)
		{
			f=1;
			break;
		}
		if(k<0)
		{
			f=-1;
			break;
		}
		if(k==0)
		continue;
	}
	if(f==0)
	f=0;
	cout<<f;
}

