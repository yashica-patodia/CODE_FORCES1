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
long long MOD=1e11+9;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
int n,m;
//vector<vector<pair<lli,lli> > >adj;
map<lli,vector<pair<lli,lli> >>adj;
priority_queue<pair<lli,lli> >pq;
vector<lli>par;
vector<lli>dis;
void printpath(lli j)
{
	if(par[j]==-1)
		return;
	//cout<<j<<" "<<par[j]<<endl;
	printpath(par[j]);
	cout<<j<<" ";
}
void solve()
{
	cin>>n>>m;
	dis.resize(n+1);
	par.resize(n+1);
	
	for(int i=0;i<=n;i++)
		dis[i]=MOD;
	fr2(i,m)
	{
		lli a,b,w;
		cin>>a>>b>>w;
		adj[a].eb(MP(b,w));
		adj[b].eb(MP(a,w));
	}
	pq.push(MP(0,1));
	dis[1]=0;
	par[1]=-1;
	while(!pq.empty())
	{
		lli v=pq.top().ss;
		pq.pop();
		for(auto j=adj[v].begin();j!=adj[v].end();j++)
		{
			lli u=(*j).ff;
			lli wei=(*j).ss;
			if(dis[u]>dis[v]+wei)
			{
				dis[u]=dis[v]+wei;
				pq.push(MP(-dis[u],u));
				par[u]=v;
			}
		}
	}
	if(dis[n]!=MOD)
	{
	cout<<1<<" ";
	printpath(n);
}
else
cout<<-1;
	//cout<<dis[n];
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
