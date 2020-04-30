#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli t,n,a,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<lli>vec;
		for(i=0;i<n;i++)
		{
			cin>>a;
			vec.push_back(a);

		}

		sort(vec.begin(),vec.end());
		vector<lli>vec2;
		lli j=(n/2)-1;
		if(n%2==1)
				vec2.push_back(vec[n/2]);
		for(i=n/2;i<n && j>=0;i++,j--)
		{
			if(n%2==0)
			{
				vec2.push_back(vec[i]);
				vec2.push_back(vec[j]);
				// cout<<vec[i]<<" ";
			}
			if(n%2==1)
			{
				if(i==(n/2))
				{
					j++;
					continue;
				}
				else
				{
					vec2.push_back(vec[i]);
					vec2.push_back(vec[j]);
				}

			}

		}
		for(i=0;i<n;i++)
		cout<<vec2[i]<<" ";
		cout<<endl;	
	}
}