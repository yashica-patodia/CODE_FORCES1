#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int i,a1,b1;
		vector<int>a,b;
		vector<pair<int,int> > ch;
		cin>>n;
		for(i=0;i<n;i++)

		{
			cin>>a1;
			a.push_back(a1);

		}
		for(i=0;i<n;i++)
		{
			cin>>b1;
			b.push_back(b1);
		}
		if(a[0]!=b[0])
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(a[0]==-1 )
			ch.push_back(make_pair(1,0));
		if(a[0]==1)
			ch.push_back(make_pair(0,1));
		if(a[0]==0)
			ch.push_back(make_pair(0,0));
		for(i=1;i<n;i++)
		{
			int f1=0,f2=0;
			int temp=a[i];
			int t1=ch[i-1].first;
			int t2=ch[i-1].second;
			if(temp==-1 || t1==1)
				f1=1;
			if(temp==1 || t2==1)
				f2=1;
			ch.push_back(make_pair(f1,f2));
		}
		int f=1;
		for(i=n-1;i>=1;i--)
		{
			if(a[i]>b[i])
			{
				int k=ch[i-1].first;
				if(k==0)
				{
					f=0;
					break;
				}
			}
			if(a[i]<b[i])
			{
				int k=ch[i-1].second;
				if(k==0)
				{
					f=0;
					break;
				}
			}
		}
		if(f==0)
			cout<<"NO"<<endl;
		if(f==1)
			cout<<"YES"<<endl;


	}

}