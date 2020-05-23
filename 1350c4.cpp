#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
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
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
lli lcm(lli a,lli b)
{
	return (a/__gcd(a,b)*b);
}
//gcd gives the prime factor which divides both the numbers whereas lcm gves those which divide at least one of them 
void solve()
{
	int n;
	cin>>n;
	lli g=0,ans=0;
	vector<lli>a(n,0);
	fr2(i,n)
	cin>>a[i];
	vector<vector<lli> >dp(2,vector<lli>(n,1));
	dp[0][0]=a[0];
	dp[1][0]=a[0];
	dp[0][1]=__gcd(a[0],a[1]);
	dp[1][1]=lcm(a[0],a[1]);

	for(int i=2;i<n;i++)
	{
		dp[0][i]=__gcd(dp[0][i-1],a[i]);//this gives pf which divide all the i+1 numbers
		dp[1][i]=lcm(dp[0][i-1],__gcd(dp[1][i-1],a[i]));//this gives prime factors which divide at least i
	}
	cout<<dp[1][n-1]<<endl;
}

int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	solve();
}