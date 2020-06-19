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
vector<vector<lli>>adj;

void solve()
{
	lli n,m;
	cin>>n>>m;
	adj.resize(n+1);
	adj.clear();
	lli deg[n+1]={0};
	lli deg2[n+1]={0};
	vector<lli>topo;
	vector<int>vis(n+1,0);
//	vis.assign(n+1,0);
	int yp=1;
	for(lli i=0;i<m;i++)
	{
		lli u,v;
		cin>>u>>v;
		if(u==v)
		{
			yp=0;
		}
		adj[u].eb(v);
		deg[v]++;
		deg2[u]++;
	}
	//lli deg2[n+1]=deg;
	lli s,d;
	cin>>s>>d;
	// if(s==d)
	// {
	// 	cout<<"NO"<<endl;
	// 	return;
	// }
	if(s==d && deg2[s]==0)
	{
		cout<<"YES"<<endl;
		return;
	}
	// if(n==1)
	// {
	// 	cout<<"NO"<<endl;
	// 	return;
	// }
	if(yp==0)
	{
		cout<<"NO"<<endl;
		return;
	}
	queue<lli>q;
	for(lli i=1;i<=n;i++)
	{
		if(deg[i]==0)
			q.push(i);

	}
	topo.clear();
	while(!q.empty())
	{
		lli vert=q.front();
		q.pop();
		topo.eb(vert);
		vis[vert]=1;
		for(auto i:adj[vert])
		{
			if(vis[i]==0)
			{
				deg[i]--;
				if(deg[i]==0)
				q.push(i);
			}
		}
	}
	if(topo.size()==n)
	{
		queue<lli>q2;
		vis.assign(n+1,0);
		q2.push(s);
		vis[s]=1;
		while(!q2.empty())
		{
			lli k=q2.front();
			q2.pop();
			if( k!=d && deg2[k]==0)
			{
				cout<<"NO"<<endl;
				return;

			}
			
			for(auto i:adj[k])
			{
				
				if(!vis[i])
				{
					vis[i]=1;
					q2.push(i);
				}

			}

		}

		for(lli i=1;i<=n;i++)
		{
			if(vis[i])
			{
				if(i!=d && deg2[i]==0 )
				{
					//f=0;
					cout<<"NO"<<endl;
					return;
				}
			}


		}
		if(vis[d] && deg2[d]==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	else
	{
		cout<<"NO"<<endl;
		return;
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
//try to declare array outside the function because it gts initilaizeed during compile time
whereas in main it gets initialized during rn time
