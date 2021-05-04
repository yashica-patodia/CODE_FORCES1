#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	string str;
	int i,j;
	getline(cin>>ws,str);
	int len=str.length();
	lli s=0;
	for(i=0;i<len-3;i++)
	{
		for(j=i;j<len;j++)
		{
			if(str[j]=='b' && str[j+1]=='e' && str[j+2]=='a' && str[j+3]=='r' )
			{
				s+=len-j-3;
				break;
			}

		}
	}
	cout<<s;

}