//increaseing the weights of components in the spsanning tree will only increse k so we dont do that
//we change the weights in the nodes outside mst
//to keep it to minimum we check for similar weights in mst and then increase its corresponding weight outside mst
#include<bits/stdc++.h>//first u need to understand when is the mst unique
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
int n,m;
vector<pair<lli,pair<int,int> >>edgel;
struct DSU
{
	int n;
	int conn;
	vector<int>par;
	vector<int>s;
	DSU(){

	}
	DSU(int _n)
	{
		n=_n;
		conn=_n;
		par.resize(n+1);
		s.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}
	}
	int find(int v)
	{
		while(v!=par[v])
		{
			par[v]=par[par[v]];
			v=par[v];
		}
		return  v;

	}
	void merge(int x,int y)
	{
		int p1=find(x);
		int p2=find(y);
		if(p1!=p2)
		{
			if(s[p1]>=s[p2])
			{
				s[p1]+=s[p2];
				par[p2]=p1;
			}
			else
			{
				s[p2]+=s[p1];
				par[p1]=p2;
			}
			conn-=1;
		}
	}
	void reset()
	{
		conn=n;
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}

	}
	int conn_comp()
	{
		return conn;
	}
	void print()
	{
		for(int i=1;i<=n;i++)
			cout<<i<<"  -->"<<par[i]<<endl;
	}
};


void solve()
{
	cin>>n>>m;
	edgel.resize(m);
	map<lli,lli>mp;
	for(int i=0;i<m;i++)
	{
		int u,v;
		lli w;
		cin>>u>>v>>w;
		edgel[i]={w,{u,v}};
		mp[w]++;
	}
	sort(all(edgel));
	for(auto i:edgel)
	{
		cout<<i.ff<<" ";
	}
	cout<<endl;
	set<lli>st;
	DSU uf(n);
	vector<pair<int,lli> >adj[n+1];
	for(auto i:edgel)
	{
		int x=i.ss.ff;
		int y=i.ss.ss;
		if(uf.find(x)!=uf.find(y))
		{
			uf.merge(x,y);
			st.insert(i.ff);
			adj[x].pb({y,i.ff});
			adj[y].pb({x,i.ff});

		}
	}
	for(int i=1;i<=n;i++)
	{
	for(auto j:adj[i])
	{
		cout<<i<<" "<<j.ff<<" "<<j.ss<<endl;
	}
}
	lli cnt=0;
	for(auto i:st)
	{
		if(mp[i]>1)
			cnt+=(mp[i]-1);

	}
	cout<<cnt<<endl;



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
