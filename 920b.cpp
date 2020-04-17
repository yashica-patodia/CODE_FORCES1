#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y,i;
		cin>>n;
		queue<pair<int,int> >qu;
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			qu.push(make_pair(x,y));

		}
		int ans;
		for(i=0;i<n;i++)
		{
			int l1=qu.front().first;
			int r1=qu.front().second;
			if(i==0 )
			{
				ans=l1;
				cout<<ans<<" ";
			}
			else
			{
				if(ans>=r1)
					cout<<0<<" ";
				else
				{
					ans=max(ans+1,l1);
					cout<<ans<<" ";
				}
			}
			qu.pop();
		}
	}
}