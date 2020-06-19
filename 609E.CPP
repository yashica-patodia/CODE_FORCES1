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
#define fr2(i,n) for(lli i=0;i<(n);i++)
#define inc2(i,a,b) for(lli i=a;i<=b;i++)
#define dec2(i,a,b) for(lli i=a;i>=b;i--)
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
typedef pair<lli,lli> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<lli> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
lli n,m;
vector<vector<pair<lli,lli> >>adj;
lli jump[200001][22];
lli mxd[200001][22];
lli lev[200001];
struct dsu
{
	lli n;
	vector<lli>par;
	vector<lli>s;
	//lli conn;
	dsu()
	{

	}
	dsu(lli _n)
	{
		n=_n;
		//conn=_n;
		par.resize(n+1);//1 to  n nodes;
		s.resize(n+1);
		for(lli i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}

	}
	lli find(lli x)
	{
		while(x!=par[x])
		{
			par[x]=par[par[x]];
			x=par[x];
		}
		return x;
	}
	void merge(lli x,lli y)
	{
		lli p1=find(x);
		lli p2=find(y);
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
			//conn-=1;
		}
	}
	void reset()
	{
		//conn=n;
		for(lli i=1;i<=n;i++)
		{
			par[i]=i;
			s[i]=1;
		}

	}
	// lli conn_comp()
	// {
	// 	return conn;
	// }
	// void prlli()
	// {
	// 	for(lli i=1;i<=n;i++)
	// 		cout<<i<<"  -->"<<par[i]<<endl;
	// }
};
void dfs(lli v,lli par,lli lvl,lli w)
{
	//tin[v]=tim++;
	jump[v][0]=par;
	if(w!=-1)
		mxd[v][0]=w;
	lev[v]=lvl;
	for(auto i:adj[v])
	{
		if(i.ff!=par)
			dfs(i.ff,v,lvl+1,i.ss);
	}
	//tout[v]=tim++;
}
void makejump()
{
	//dfs(1,0,0);
	for(lli i=1;i<=20;i++)
	{
		for(lli j=1;j<=n;j++)
		{
			jump[j][i]=jump[jump[j][i-1]][i-1];
			mxd[j][i]=max(mxd[j][i-1],mxd[jump[j][i-1]][i-1]);
		}
	}
}
lli query(lli u,lli v)
{
	if(u==v)
		return u;
	if(lev[u]>lev[v])
		swap(u,v);///v is the bottomost vertex
	for(lli i=20;i>=0;i--)
	{
		if(lev[u]+(1<<i)<=lev[v])
		{
			v=jump[v][i];
		}
	}
	if(u==v)
		return u;
	for(lli i=20;i>=0;i--)
	{
		if(jump[u][i]!=jump[v][i])//find thbe last node where they were diff
		{
			u=jump[u][i];
			v=jump[v][i];
		}

	}
	return jump[v][0];
}
lli query2(lli u,lli v)
{
	//pair<lli,lli> pp;
	//pp.ff=lli_MAX;
	//pp.ss=lli_MIN;
	lli pp=INT_MIN;
	if(lev[u]>lev[v])
		swap(u,v);
	for(lli i=20;i>=0;i--)
	{
		if(lev[u]+(1<<i)<=lev[v])
		{
			//pp=min(pp,mnd[v][i]);
			pp=max(pp,mxd[v][i]);
			v=jump[v][i];

		}
	}
	return pp;
}
void solve()
{
	cin>>n>>m;
	vector<pair<pair<lli,lli>,pair<lli,lli>>>edgel(m+1);
	//vector<pair<pair<lli,lli>,pair<lli,lli>>>edgel2(m+1);
	for(lli i=1;i<=m;i++)
	{
		lli a,b,c;
		cin>>a>>b>>c;
		edgel[i]={{c,i},{a,b}};
		//edgel2[i]={{c,i},{a,b}};
		//edgel[i]=({{c,i},{a,b}});
	}
	sort(all(edgel));
	vector<bool>vis(m+1,false);
	
	adj.resize(n+1);
	dsu uf(n);
	lli mst_cst=0;
	for(auto i:edgel)
	{
		lli x=i.ss.ff;
		lli y=i.ss.ss;
		if(uf.find(x)!=uf.find(y))
		{
			mst_cst+=i.ff.ff;
			vis[i.ff.ss]=true;
			//cout<<i.ff.ss<<endl;
			adj[x].pb({y,i.ff.ff});
			adj[y].pb({x,i.ff.ff});
			uf.merge(x,y);
		}
	}
	//cout<<mst_cst<<endl;
	dfs(1,0,0,-1);
	makejump();
	vector<lli>yp(m+1);
	for(lli i=1;i<=m;i++)
	{
		//cout<<vis[i]<<i<<endl;
		lli j=edgel[i].ff.ss;
		if(vis[j])
		{
			yp[j]=mst_cst;
			//cout<<mst_cst<<endl;
			continue;
		}
		//lli j=edgel[]
		lli x=edgel[i].ss.ff;
		lli y=edgel[i].ss.ss;
		//cout<<x<<" "<<y<<endl;
		lli val=edgel[i].ff.ff;
		lli lca=query(x,y);
		//cout<<val<<" "<<lca<<endl;
		if(lca==x || lca==y)
		{
			lli ans=query2(x,y);
			yp[j]=mst_cst-ans+val;
			//cout<<mst_cst-ans+val<<endl;

		}
		else
		{
			lli a1=query2(x,lca);
			lli a2=query2(y,lca);
			a1=max(a1,a2);
			yp[j]=mst_cst-a1+val;
			//cout<<mst_cst-a1+val<<endl;

		}
	}
	for(auto i=1;i<=m;i++)
		cout<<yp[i]<<endl;
	


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
	// lli t;
	// cin>>t;
	// for(lli i=1;i<=t;i++)
	// {
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	solve();
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
