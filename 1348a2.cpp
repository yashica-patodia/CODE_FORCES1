#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
double startTime;
double getCurrentTime()
{
	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x);
		x=(x*x);
	}
	return res;
}
lli inver(lli num)
{
	return pwr(num,MOD-2);
}
lli findncr(lli n,lli r)
{
	r=min(r,n-r);
	if(n==0||n==1||r==0)
		return 1;
	lli numer=1;
	for(lli i=n;i>=n-r+1;i--)
		numer=(numer*i)%MOD;
	lli den=1;
	for(lli i=2;i<=r;i++)
		den=(den*i)%MOD;
	den=inver(den);
	lli res=(numer*den)%MOD;
	return res;
}
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
	// 	lli sum1=0,sum2=0;
	// 	if((n/2%2)==0)
	// 	{
	// 	for(int i=1;i<=n/2;i++)
	// 	{
	// 		if(i%2==0)
	// 		{
	// 			sum2+=pwr(2,i)+pwr(2,n-i+1);

	// 		}
	// 		else
	// 			sum1+=pwr(2,i)+pwr(2,n+1-i);

	// 	}
	// }
	// else
	// {
	// 	for(int i=1;i<n/2;i++)
	// 	{
	// 		if(i%2==0)
	// 		{
	// 			sum2+=pwr(2,i)+pwr(2,n-i+1);

	// 		}
	// 		else
	// 			sum1+=pwr(2,i)+pwr(2,n+1-i);

	// 	}
	// 	sum2+=pwr(2,(n/2)+1);
	// 	sum1+=pwr(2,n/2);

	// }
		lli sum1=0,sum2=0;
		sum1=pwr(2,n);
		int i;
		for(i=1;i<=(n/2)-1;i++)
			sum1+=pwr(2,i);
		for(i=n/2;i<n;i++)
			sum2+=pwr(2,i);
	//cout<<sum1<<" "<<sum2<<endl;
	cout<<abs(sum2-sum1)<<endl;
}
}