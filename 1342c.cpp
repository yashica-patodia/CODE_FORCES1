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

typedef vector<plli> vplli;
long long MOD=1000000009;
lli find(lli k,lli lcm);

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli gcd(lli a, lli b )
{
	if(b==0)
		return a;
	return gcd(b,a%b);

}

lli a,b,q;
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
		lli lcm;
		cin>>a>>b>>q;
		 lcm=(a*b)/gcd(a,b);
		if(a>b)
			swap(a,b);
		//cout<<lcm<<endl;
		while(q--)
		{
			//cout<<q;
			lli l,r;
			cin>>l>>r;
			lli tot=r-l+1;
			//cout<<tot<<endl;
			//cout<<find(r)<<endl;
			//cout<<find(l-1)<<endl;
			tot=tot-find(r,lcm)+find(l-1,lcm);
			cout<<tot<<" ";
			


			
		}
		cout<<endl;
	}
}
lli find(lli k,lli lcm)
{
	lli p=k/lcm;
	lli tot=p*b;
	if(k>=(p*lcm)+b-1)
		tot+=b-1;
	else

	tot+=k%lcm;
	return tot;


	
}