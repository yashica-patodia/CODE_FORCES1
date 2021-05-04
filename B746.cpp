#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	string s;
	cin>>s;
	string *s2;
	s2=new string[n];
	
	if(n%2!=0)
	{
		int m1=n/2;
		int m2=n/2;
		s2[m1]=s[0];
		for(i=1;i<n;i++)
		{
			if(i%2==0)
			{
				s2[m1+1]=s[i];
				m1++;
			}
			else
			{
				s2[m2-1]=s[i];
				m2--;
			}
		}
	}
	else
	{
		int m1=(n/2)-1;
		int m2=(n/2)-1;
		s2[m1]=s[0];
		for(i=1;i<n;i++)
		{
			if(i%2!=0)
			{
				s2[m1+1]=s[i];
				m1++;
			}
			else
			{
				s2[m2-1]=s[i];
				m2--;
			}
		}
	}

	for(i=0;i<n;i++)

	cout<<s2[i];
	}


