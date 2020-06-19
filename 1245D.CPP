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
int n;
vector<pair<int,int> >vp;
vector<lli>c;
vector<lli>k;
struct DSU
{
	///int conn;
	//int par[N],s[N];
	vector<int>par;
	vector<int>s;
	int n;
	DSU(){}
	DSU(int _n)
	{
		n=_n;
		par.assign(n,0);
		s.assign(n,0);
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			s[i]=1;
		}
		//conn=n;
	}
	int find(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}
	// int getsize(int k)
	// {
	// 	return s[find[k]];
	// }
	void unite(int u,int v)
	{
		int p1=find(u);
		int p2=find(v);
		if(p1==p2)
			return;
		//conn--;
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
	}
};
lli dis(pair<int,int>p1,pair<int,int>p2)
{
	return ((abs(p1.ff-p2.ff)+abs(p1.ss-p2.ss)));
}
void solve()
{
	cin>>n;
	vp.clear();
	c.resize(n);
	//c.clear();
	k.resize(n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		vp.pb({x,y});
	}
	for(int i=0;i<n;i++)
	{
		//lli p;
		cin>>c[i];
		
	}
	for(int i=0;i<n;i++)
	{
		//lli p;
		cin>>k[i];
		//k[i]=p;
	}
	vector<pair<lli,pair<int,int > >>edgel;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			edgel.pb({((k[i]+k[j])*dis(vp[i],vp[j])),{i,j}});
		}
	}
	for(int i=0;i<n;i++)
		edgel.pb({c[i],{i,n}});

	DSU uf(n+1);
	sort(all(edgel));
	vector<vector<int> >adj;
	adj.resize(n+1);
	int cnt=0;
	lli mst_cst=0;
	for(auto i:edgel)
	{
		int x=i.ss.ff;
		int y=i.ss.ss;
		if(uf.find(x)!=uf.find(y))
		{
			mst_cst+=i.ff;
			uf.unite(x,y);
			if(x>y)
				swap(x,y);//y is greater
			adj[y].pb(x);
			if(y!=n)
				cnt++;
		}




		}
		cout<<mst_cst<<endl;
		cout<<adj[n].size()<<endl;
		for(auto i:adj[n])
			cout<<i+1<<" ";
		cout<<endl;
		cout<<cnt<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto j:adj[i])
				cout<<i+1<<" "<<j+1<<endl;

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
