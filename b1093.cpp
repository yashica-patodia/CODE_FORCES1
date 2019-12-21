#include<bits/stdc++.h>
using namespace std;
int palin(string s);
int main()
{
	int t;
	cin>>t;
	int i;
	while(t--)
	{
	string temp;
	getline(cin>>ws,temp);
	int k=palin(temp);
	if(k==0)
	{
		int l=temp.length();
		char ch=temp[0];
		int f=1;
		for(i=0;i<l;i++)
		{
			if(ch!=temp[i])
			{

				f=0;
				break;
			}
		}
		if(f==1)
		cout<<-1<<endl;
		else
		{
			for(i=1;i<temp.length();i++)
			{
			if(temp[i]!=ch)
			{
			swap(temp[0],temp[i]);
				break;
			}
			}
			cout<<temp<<endl;

		}
	}
	else
	cout<<temp<<endl;
	}
}
int palin(string s)
{
int i;
int l=s.length();
for(i=0;i<l/2;i++)
{
if(s[i]!=s[l-1-i])
return 1;
}
return 0;
}
