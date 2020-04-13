#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli t,n,a,i;
	cin>>t;
	while(t--)
	{
		lli c=0;
		cin>>n;
		
		vector<lli>vec,vec2;
		for(i=0;i<n;i++)
		{
			cin>>a;
			vec.push_back(a);

		}
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		vec2.push_back(vec[0]);
		for(i=1;i<n;i++)
		{
			if(vec[i]>vec2[i-1])
				vec2.push_back(vec[i]);
			else
				vec2.push_back(vec2[i-1]);

		}
		for(i=1;i<n;i++)
		{
			if(vec[i]==vec2[i])
				continue;
			else
			{
				 c=max(c,1+(lli)(log2(vec2[i]-vec[i])));
			}
		}
		cout<<c<<endl;


	}

}