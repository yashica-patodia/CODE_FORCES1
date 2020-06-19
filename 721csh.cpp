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

typedef   int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
//this is a very common problem where we use dfs and dp together and then calculate the path
lli n,m,T;
vector<vector<pair<lli,lli> >>adj;
vector<vector<pair<lli,lli>>>dp;
vector<lli>ans;
lli dfs(lli i,lli j)//time taken to visit i the node using j places
{
	if(j<=0)
		return MOD;
	if(dp[i][j].ff!=-1)
		return dp[i][j].ff;
	dp[i][j].ff=MOD;
	for(auto ch:adj[i])
	{
		lli p=dfs(ch.ff,j-1)+ch.ss;
		if(p<dp[i][j].ff)
			dp[i][j]={p,ch.ff};
	}
	return dp[i][j].ff;

}
void solve()
{
	
	cin>>n>>m>>T;
	adj.resize(n+1);
	//dp.resize(n+1);
	dp.assign(n+1,vector<pair<lli,lli> >(n+1,{-1,-1}));
	dp[1][1]={0,-1};
	for(int i=0;i<m;i++)
	{
		lli x,y,w;
		cin>>x>>y>>w;
		adj[y].pb({x,w});
	}
	for(int i=n;i>=1;i--)
	{
		if(dfs(n,i)<=T)
		{
			cout<<i<<endl;
		
		lli	temp=dp[n][i].ss;
			ans.eb(n);
			//ans.eb(temp);
			lli p=i;
			while(temp!=-1)
			{
				ans.eb(temp);
				temp=dp[temp][--p].ss;
				


			}
			for(int j=ans.size()-1;j>=0 ;j--)
			{
				cout<<ans[j]<<" ";
			}
			cout<<endl;
			return ;
		}

		}
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
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
	solve();
}
