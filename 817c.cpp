#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int check(lli num,lli s);

int main()
{
	lli n,s;
	cin>>n>>s;
	lli lb=0,ub=n+1;
	while(lb<ub-1)
	{
		lli mm=lb+(ub-lb)/2;

		if(check(mm,s))
			ub=mm;
		else
			lb=mm;
	}
	//cout<<lb<<"  "<<ub<<endl;
	lli num=n-ub+1;
	cout<<num<<endl;
}
int check(lli num,lli s)
{
	lli temp=num;
	lli sum=0;
	while(temp!=0)
	{
		lli d=temp%10;
		sum+=d;
		temp/=10;

	}
	if(num-sum>=s)
		return 1;
	else
		return 0;
}
