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
lli n;
vector<vector<lli>>adj;
//vector<pair<lli,lli>>adj;
//const lli N=100001;
//int tim=0;
lli jump[100001][20]={{0}};
lli lev[100001]={0};
//lli tin[N],tout[N],lev[N];
lli si[100001];
void dfs(lli v,lli par,lli lvl)
{
	//tin[v]=tim++;
	//cout<<v<<" "<<par<<" "<<lvl<<endl;
	jump[v][0]=par;
///	cout<<jump[v][0]<<"yp"<<endl;
	lev[v]=lvl;
	si[v]=1;
	for(auto i:adj[v])
	{
		//cout<<i<<"--> "<<v<<endl;
		if(i!=par)
		{
			dfs(i,v,lvl+1);
			si[v]+=si[i];
		}

	}
	//tout[v]=tim++;
}
void makejump()
{
	dfs(1,-1,0);
	for(lli i=1;i<20;i++)//always statrt this with 1 and not 0
	{
		for(lli j=1;j<100001;j++)
			jump[j][i]=jump[jump[j][i-1]][i-1];
	}
}
lli query(lli u,lli v)
{
	if(u==v)
		return u;
	if(lev[u]>lev[v])
		swap(u,v);
	for(lli i=19;i>=0;i--)
	{
		if(lev[u]+(1<<i)<=lev[v])
			v=jump[v][i];
	}
	if(u==v)
		return u;
	for(lli i=19;i>=0;i--)
	{
		if(jump[u][i]!=jump[v][i])
		{
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	return jump[v][0];
}
// bool is_ancestor(int u,int v)//u is an ancestor of v
// {
// 	return  (tin[u]<=tin[v] && tout[u]>=tout[v]);
// }
// lli find_ancestor(lli a,lli b)//find the child of b which is ancestor of a
// {
// 	for(lli i=19;i>=0;i--)
// 	{
// 		if(!is_ancestor(jump[a][i],b))
// 			a=jump[a][i];
// 	}
// 	return a;
// }
lli distance(lli u,lli v)
{
	return lev[u]+lev[v]-2*lev[query(u,v)];
}

void solve()
{
	cin>>n;
	adj.resize(n+1);
	for(lli i=0;i<n-1;i++)
	{
		lli a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		//adj.pb({a,b});
	}
	makejump();
	// for(int i=1;i<=n;i++)
	// 	cout<<si[i]<<endl;
	// for(lli i=0;i<3;i++)
	// {
	// 	for(lli j=1;j<=n;j++)
	// 		cout<<jump[j][i]<<endl;
	// }
	lli m;
	cin>>m;
	while(m--)
	{
		lli x,y;
		cin>>x>>y;
	//	cout<<x<<y<<endl;
		if(x==y)
		{
			//cout<<1<<endl;
			cout<<n<<endl;
			continue;
		}
		if(distance(x,y)%2==1)
		{
			//cout<<2<<endl;
			cout<<0<<endl;
			continue;
		}
		lli lca=query(x,y);
		if(distance(x,lca)==distance(y,lca))
		 {
		 	//cout<<3<<endl;
		// 	lli x1=find_ancestor(x,lca);
		// 	lli y1=find_ancestor(y,lca);
		 	for(lli i=19;i>=0;i--)
		 	{
		 		if(jump[x][i]!=jump[y][i])
		 		{
		 			x=jump[x][i];
		 			y=jump[y][i];
		 		}
		 	}
			cout<<n-si[x]-si[y]<<endl;
			continue;
		}
		else
		{
			////cout<<4<<endl;
			////cout<<x<<" "<<lev[x]<<endl;
			//cout<<y<<" "<<lev[y]<<endl;
			if(lev[x]<lev[y])//x ka depth zyada hai
				swap(x,y);
			lli temp1=x;
			lli temp2=y;
			//cout<<temp1<<" "<<temp2<<endl;
			lli dis=distance(x,y);
			//cout<<dis<<endl;
			dis=dis/2;
			for(lli i=19;i>=0;i--)
			{
				if(dis&(1<<i))
				{
					//cout<<i<<" "<<temp1;
					//cout<<jump[temp1][i];
					temp1=jump[temp1][i];
				}
			}
			//cout<<temp1<<endl;
			//if()
			dis--;
			for(lli i=19;i>=0;i--)
			{
				if(dis&(1<<i))
					x=jump[x][i];
			}
			cout<<si[temp1]-si[x]<<endl;

			//last wala condition kaise nikalenge??
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
