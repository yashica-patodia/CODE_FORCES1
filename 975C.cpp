#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
lli check(lli arr);
lli n,q;
vector<lli>a,k;
int main()
{
	cin>>n>>q;
	//a.resize(n);
	lli i;
	for(i=0;i<n;i++)
	{
		lli p;
		cin>>p;
		if(i==0)
			a.push_back(p);
		else
			a.push_back(p+a[i-1]);

	}
	for(i=0;i<q;i++)
	{
		lli p;
		cin>>p;
		k.push_back(p);

	}
	lli last=0,arr=0;

	for(i=0;i<q;i++)
	{
		k[i]+=last;
		lli ff=check(k[i]);
		//cout<<ff<<endl;
		if(ff>=(n-1))
		{
			cout<<n<<endl;
			last=0;
			continue;
		}
		last=k[i];
		cout<<n-ff-1<<endl;

	}

}
lli check(lli arr)
{
	lli lb=0,ub=n,mm;
	while(lb<ub-1)
	{
		mm=lb+(ub-lb)/2;
		if(arr>=a[mm])
			lb=mm;
		else
			ub=mm;
		//cout<<lb<<" "<<ub<<endl;

	}
	return lb;
}
