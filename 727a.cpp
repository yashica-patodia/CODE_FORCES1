#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	vector<int>vec;
	lli a,b,i;
	cin>>a>>b;
	// lli temp=b;
	if(b%10!=1 && b%2!=0)
		cout<<"NO"<<endl;
	else
	{
		
		vec.push_back(b);
		while(b>a)
		{
			if(b%10==1)
			{
				b=b-1;
				b=b/10;
			}
		else if(b%2==0)
				b=b/2;
			// cout<<b<<" ";
			vec.push_back(b);
			if(b==a)
			{
				break;
			}
		else	if(b%10!=1 && b%2!=0)
			{
				cout<<"NO";
				break;
			}
		}
		if(b==a)
		{
	cout<<"YES"<<endl;
	cout<<vec.size()<<endl;
	for(i=vec.size()-1;i>=0;i--)
	{
		cout<<vec[i]<<" ";
	}}
	else
	{
		if(b<a)
			cout<<"NO";
	}
}
}