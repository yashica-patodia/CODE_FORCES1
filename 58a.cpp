#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	string str("hello");
	int l=str.length();
	
	cin>>s;
	string s1(s);
	int l2=s.length();
	int f=0;
	int i;
	if(l2>=1 && l2<=100)
	{
		for(i=0;i<l;i++)
		{
			int pos=s1.find(str[i]);
			if(pos!=-1)
			{
				s1=s1.substr(pos+1);

				continue;
			}
			else
			{
				f=1;
				break;
			}
		}
		if(f==0)	
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	else
	cout<<"out of range";
}

