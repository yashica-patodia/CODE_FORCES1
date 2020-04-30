#include<bits/stdc++.h>
using namespace std;
typedef  long long int lli;
int main()
{
	lli t,i;
	while(t--)
	{
		string str;
		vector<string>vec;
		for(i=0;i<9;i++)
		{
			cin>>str;
			if(str[i]=='9')
				str[i]=(char)('9'-'0'-1);
				
			else
				str[i]=(char)(str[i]-'0'+1);
			cout<<str[i]<<endl;
			vec.push_back(str);


		}
		for(i=0;i<9;i++)
			cout<<vec[i]<<endl;

	}
}