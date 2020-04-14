#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli res(lli k,vector<lli>a,lli n);
int main()
{
	lli n,S,p,i;
	cin>>n>>S;
	vector<lli>a;
	for(i=0;i<n;i++)
	{
		cin>>p;
		a.push_back(p);
	}
	lli lb=0,ub=n+1;
	while(lb<ub-1)
	{
		lli m=lb+(ub-lb)/2;
		//cout<<res(m)<<" ";
		if(res(m,a,n)<=S)
			lb=m;
		else
			ub=m;
		//cout<<lb<<" "<<ub<<endl;
	}
	cout<<lb<<" "<<res(lb,a,n)<<endl;

}
lli res(lli k,vector<lli>a,lli n)
{
	lli i;
	vector<lli>b(n,0);
	for(i=0;i<n;i++)
	{
		b[i]=a[i]+(i+1)*k;

	}
	lli sum=0;
	sort(b.begin(),b.end());
	for(i=0;i<k;i++)
		 sum+=b[i];
		//cout<<"S"<<sum<<endl;
	return sum;
}