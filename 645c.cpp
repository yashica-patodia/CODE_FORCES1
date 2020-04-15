#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,k;
vector<lli>vec;
int main()
{
	
	cin>>n>>k;
	string str;
	cin>>str;
	
	for(i=0;i<str.length();i++)
	{
		if(str[i]=='0')
			vec.push_back(i+1);
	}
	lli lb=1,ub=vec[n-1]-vec[0]+1,mm;
	// if(ub%2==0)
	// 	pos=ub/2;
	// else
	// 	pos=(ub+1)/2;
	while(lb<ub-1)
	{
		mm=lb+(ub-lb)/2;
		if(check(mm))
			ub=mm;
		else
			lb=mm;
	}
	cout<<ub<<endl;

}
int check(lli k2)
{
	lli p=0;
	lli i;
	for(i=1;i<n;i++)
	{
		lli diff=vec[i]-vec[i-1];
		p+=(diff-1)/k2;

	}
	if(p>=k)
		return 1;
	else
		return 0;
}