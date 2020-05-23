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
lli mod;
#define addm(x,y) (x+y>=mod? (x+y-mod):(x+y))
// (N,M,B)->NO LINES/ONE LINE->(N-1,M,B)+(N,M-1,B-ARR[N])
// DP[N][M][B]=NO OF WAYS SUCH I-N PROGRAMMERS HAVE TO WRITE M LINES TO MAKE B BUGS
// WHAT INFO DOES ITH NEED TO MOVE IT TO ITH+1
//for two -d arrayy dont initialize it like this
//dp[10][10]={0}
void solve()
{
	lli n,m,b;
	cin>>n>>m>>b>>mod;
	lli dp[2][m+1][b+1];
	mset(dp,0);
	lli arr[n+1];
	for(lli i=1;i<=n;i++)
		cin>>arr[i];

	dp[0][0][0]=1;
	//cout<<addm(1,102);
	for(lli i=1;i<=n;i++)
	{
		for(lli j=1;j<=m;j++)
		{
			for(lli p=0;p<=b;p++)
			{
				if(p>=arr[i])
				dp[i%2][j][p]=(dp[(i-1)%2][j][p]+dp[i%2][j-1][p-arr[i]])%mod;
			}
		}
		for(lli j1=1;j1<=m;j1++)
		{
			for(lli p1=0;p1<=b;p1++)
				cout<<dp[i%2][j1][p1]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	lli ans=0;
	for(lli i=0;i<=b;i++)
		ans=(ans+dp[n%2][m][i])%mod;
	cout<<ans<<endl;
	//for()


}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	clock_t start,end;
	// start=clock();
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
	solve();
}