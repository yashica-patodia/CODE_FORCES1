#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli>vec;
lli cnt[200010];
lli n,k;
int check(lli len);
int main()
{
	vector<lli>s;
	
	cin>>n>>k;
	lli i;
	for(i=0;i<n;i++)
	{
		lli p;
		cin>>p;
		s.push_back(p);
		cnt[p]++;

	}
	lli lb=1,ub=n+1;
	while(lb<ub-1)
	{
		lli mm=lb+(ub-lb)/2;
		if(check(mm))
			lb=mm;
		else
			ub=mm;
	}
	lli ff=check(lb);
	for(i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";

}
int check(lli len)
{
	vec.clear();
	lli i,j;
	lli mx=200010;
	for(i=0;i<mx;i++)
	{
		lli p=min(cnt[i]/len,k-vec.size());
		for(j=0;j<p;j++)
			vec.push_back(i);
	}
	if(vec.size()==k)
		return 1;
	else
		return 0;
}