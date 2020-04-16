#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int check(lli k2,int x,int y,int a,int b,vector<lli>vec,lli k,int n);
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n,i;
		cin>>n;
		vector<lli>vec;
		for(i=0;i<n;i++)
		{
			lli p;
			cin>>p;
			vec.push_back(p);
		}
		sort(vec.begin(),vec.end(),greater<lli>());
		int a,b,x,y;
		cin>>x>>a>>y>>b;
		lli k;
		cin>>k;
		lli lb=0,ub=n;
		while(lb<=ub)
		{
			lli mm=lb+(ub-lb)/2;
			if(check(mm,x,y,a,b,vec,k,n))
				ub=mm-1;
			else
				lb=mm+1;
			//cout<<check(mm,x,y,a,b,vec,k,n)<<" ";
			//cout<<lb<<" "<<ub<<endl;
		}
		if(lb>n)
			cout<<-1<<endl;
		else

		cout<<lb<<endl;
	}
}
int check(lli k2,int x,int y,int a,int b,vector<lli>vec,lli k,int n)
{
	lli i,cxy=0,cx=0,cy=0,ans=0;
	for(i=0;i<k2;i++)
	{
		if((i+1)%a==0 && (i+1)%b==0)
			cxy++;
	
	else	if((i+1)%a==0)
			cx++;
	
	else	if((i+1)%b==0)
			cy++;
	}
	if(x>=y)
	{
	for(i=0;i<cxy;i++)
	ans+=vec[i]*(x+y)*.01;
	for(i=0;i<cx;i++)
	ans+=vec[i+cxy]*(x)*.01;
	for(i=0;i<cy;i++)
	ans+=vec[i+cxy+cx]*y*.01;	
	}	
	else
	{
		for(i=0;i<cxy;i++)
	ans+=vec[i]*(x+y)*.01;
	for(i=0;i<cy;i++)
	ans+=vec[i+cxy]*(y)*.01;
	for(i=0;i<cx;i++)
	ans+=vec[i+cxy+cy]*x*.01;	
	}
if(ans>=k)
	return 1;
else
	return 0;
}
			
		