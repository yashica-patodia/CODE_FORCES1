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
//maximum edge weight that should be removed so that the the graph has no cycles
//c>C should not contain any loop
//sort the c>=C in order of topo sort
int n,m;
int N=100001;
vector<pair<pair<lli,lli> ,pair<lli,lli>>>adj(N);
vector<vector<int>>g(N);
vector<lli>vis(N);
vector<lli>deg(N);
vector<lli>t;
vector<lli>ans2;
//vector<lli>c;
bool check(lli k)
{
	g.clear();
	g.resize(n+1);
	vis.resize(n+1);
	vis.assign(n+1,0);
	deg.resize(n+1);
	deg.assign(n+1,0);
	for(int i=0;i<m;i++)
	{
		
			if(adj[i].ss.ff>k)
			{
				g[adj[i].ff.ff].pb(adj[i].ff.ss);
				deg[adj[i].ff.ss]++;
			}

	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
			q.push(i);

	}
	t.clear();
	while(!q.empty())
	{
		int vert=q.front();
		q.pop();
		t.eb(vert);
		vis[vert]=1;
		for(auto i:g[vert])
		{
			if(vis[i]==0)
			{
				deg[i]--;
				if(deg[i]==0)
				q.push(i);
			}
		}
	}
	if(t.size()==n)
		return true;
	else
		return false;


}
void topo(int p)
{
	g.clear();
	g.resize(n+1);
	vis.resize(n+1);
	vis.assign(n+1,0);
	deg.resize(n+1);
	deg.assign(n+1,0);

	//priority_queue<int>q;
	queue<int>q;
	for(int i=0;i<m;i++)
	{
		if(adj[i].ss.ff>p)
			{
				g[adj[i].ff.ff].pb(adj[i].ff.ss);
				deg[adj[i].ff.ss]++;
			}
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
			q.push(i);

	}
	t.clear();
	while(!q.empty())
	{
		int vert=q.front();
		q.pop();
		t.eb(vert);
		vis[vert]=1;
		for(auto i:g[vert])
		{
			if(vis[i]==0)
			{
				deg[i]--;
				if(deg[i]==0)
				q.push(i);
			}
		}
	}
	int ind[n+1];
	for(int i=0;i<n;i++)
		ind[t[i]]=i;
	//AB WE HAVE THE OPTION TO CHANGE THE DIRECTION OF C<=ANS AB AGAR USSE TOPO SORT KE ORDER MEIN SORT KAR DE  KOI CYCLE NAHI HIGA GUARANTEE
	for(int i=0;i<m;i++)
	{
		if(adj[i].ss.ff<=p)
		{
			if(ind[adj[i].ff.ff]>ind[adj[i].ff.ss])
				ans2.eb(i);
		}
	}
}
void solve()
{
	
	cin>>n>>m;
	// adj.clear();
	// adj.resize(m);
	// c.resize(n+1);
	for(int i=0;i<m;i++)
	{
		lli u,v,c;
		cin>>u>>v>>c;
		//adj[i]=({{u,v},{c,i}});
		adj[i]=MP(MP(u,v),MP(c,i));

	}
	lli lb=0,ub=1e9,ans=ub;
	while(ub>=lb)
	{
		lli mm=lb+(ub-lb)/2;
		if(check(mm))//CHECK FUNCTION MEIN YEHI CHECK KARNA HAI KI FOR ANY EDGE >MM AGAR EK CYCLE FORM HO RAHA HAI KI NAHI
		{
			ans=mm;
			ub=mm-1;
		}
		else
			lb=mm+1;

	}
	//bool k=check(ans);

	topo(ans);
	cout<<ans<<" ";
	cout<<ans2.size()<<endl;
	for(auto i:ans2)
		cout<<i+1<<" ";

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
// Linearity of expectation --
// EX(ax+by)=a*E(x)+b*E(y)

// expectation is similar to mean 
// summation of p(i)*(i);
