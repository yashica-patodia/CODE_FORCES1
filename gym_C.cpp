#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int n,c=0,i;
	lli s,currs=0,a;
	cin>>n>>s;
	map<lli,int>mp;

	for(i=0;i<n;i++)
	{
		cin>>a;
		currs+=a;
		//if(currs==s)
			//c++;
		///cout<<c<<endl;
		if(mp.find(currs-s)!=mp.end() )
			c+=mp[currs-s];
		mp[currs]=mp[currs]+1;
		//cout<<mp[currs]<<endl;

	}
	cout<<c;

}