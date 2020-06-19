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
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
//vector<pair<lli,pair<lli,lli>>edgel;
vector<pair<lli,pair<lli,lli> >>edgel;
lli n,m;
vector<lli>a;

void solve()
{
	cin>>n>>m;
	a.resize(n+1);
	for(lli i=0;i<n;i++)
	{
		cin>>a[i+1];

	}
	edgel.clear();
	for(lli i=0;i<m;i++)
	{
		lli u,v;
		cin>>u>>v;
		// if(u==v)
		// 	continue;
		// if(a[u]==a[v])
		// 	continue;
		// if(a[u]>a[v])
		
		// 	swap(u,v);
		if(a[v]>a[u])
		
		edgel.pb({a[v]-a[u],{u,v}});
	else if(a[v]<a[u])
		edgel.pb({a[u]-a[v],{v,u}});


	}
	sort(all(edgel));
	if(n==1)
	{
		cout<<1<<endl;
		return;
	}
	for(auto i:edgel)
	{
		cout<<i.ff<<" "<<i.ss.ff<<" "<<i.ss.ss<<endl;
	}
	//lli dp[n+1]={0};
	vector<lli>dp(n+1,0);
	lli prev[n+1]={0};
	dp[0]=0;
	for(auto i:edgel)
	{
		lli x=i.ss.ff;
		lli y=i.ss.ss;
		lli w=i.ff;
		//cout<<x<<" "<<y<<" "<<w<<endl;
		if(dp[y]<dp[x]+1 && w>prev[x])
		{
			dp[y]=dp[x]+1;

			prev[y]=w;
			//cout<<dp[y]<<endl;
		}
	}
	cout<<*max_element(all(dp))+1<<endl;

}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	// clock_t start,end;
	// start=clock();
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	//cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	solve();
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
