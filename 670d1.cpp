#include<bits/stdc++.h>
using namespace std;
typedef  unsigned long long int lli;
int check(lli k2,vector<lli>a,vector<lli>b,lli k);



int main()
{
	lli n,k;
	vector<lli>a,b;
	cin>>n>>k;
	lli i;
	for(i=0;i<n;i++)
	{
		lli p;
		cin>>p;
		a.push_back(p);
		//sum1+=p;

	}
	for(i=0;i<n;i++)
	{
		lli p;
		cin>>p;
		b.push_back(p);
		//sum2+=p;
	}
	//cout<<sum1<<" "<<sum2<<endl;
	lli lb=0,ub=1e10;
	while(lb<ub-1)
	{
		lli mm=lb+(ub-lb)/2;
		if(check(mm,a,b,k))
			lb=mm;
		else
			ub=mm;
		//cout<<lb<<" "<<ub<<" "<<mm<<endl;
	}
	cout<<lb<<endl;
}
int check(lli k2,vector<lli>a,vector<lli>b,lli k)
{
		lli i,m=0;

	// vector<lli>a1,b1;
	// for(i=0;i<a.size();i++)
	// 	a1.push_back(a[i]);
	// for(i=0;i<b.size();i++)
	// 	b1.push_back(b[i]);
	// lli temp=k;
	for(i=0;i<a.size();i++)
	{
		if(a[i]*k2>b[i])
			m+=k2*a[i]-b[i];
		
	}
	if(m>k)
	return 0;
else
	return 1;
}