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
lli n,m,k;
set<lli>st;
vector<vector<int >>adj;
vector<lli>dis;
vector<lli>par;
void solve()
{
	cin>>n>>m>>k;
	//a.resize(k);
	adj.resize(n+1);
	dis.resize(n+1);
	par.resize(n+1);
	for(lli i=0;i<k;i++)
	{
		lli p;
		cin>>p;
		//cout<<p<<endl;
		st.insert(p);

	}
	for(lli i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].eb(y);
		adj[y].eb(x);
	}
	for(lli i=0;i<=n;i++)
		dis[i]=MOD;
	 vector<bool>vis(n+1,false);
	queue<lli>pq;
	pq.push(1);
	//pq.push({0,-1});
	dis[1]=0;
	par[1]=-1;
	vis[1]=true;
	//cout<<dis[1]<<" "<<dis[2]<<endl;
	
	//cout<<vis[1];
	while(!pq.empty())
	{
		lli v=pq.front();
		//cout<<v<<endl;
		// if(vis[v])
		// 	continue;
		// vis[v]=true;
		pq.pop();
		for(auto i:adj[v])
		{
			int u=i;
			if(!vis[i])
			{
				vis[i]=true;
				dis[u]=dis[v]+1;
				par[i]=v;
				pq.push(i);
			}

		}
	}
	 //cout<<dis[n]<<" ";
	lli end=n;
	lli c=0;
	for(int i=end;i!=-1;i=par[i])
	{
		if(st.find(i)!=st.end())
			c++;
		//cout<<c<<endl;

	}
	if(k-c>=1)
	{
		cout<<dis[n]<<endl;
	}
	else
	{
		lli e=n;
		for(lli i=e;i!=-1;i=par[i])
		{
			if(st.find(i)!=st.end())
			{
				if(st.find(par[i])!=st.end())
				{
					cout<<dis[n]<<endl;
					return;
				}
			}
		}
		//auto it=st.begin();
		//lli yp=dis[*it];
		vector<pair<lli,lli>>temp;
		//temp.resize()
		for(auto it=st.begin();it!=st.end();it++)
		{
			//cout<<*it<<" ";
			temp.pb({dis[*it],*it});

		}
		sort(all(temp));
		lli ans=temp[1].ff-temp[0].ff;
		for(lli i=2;i<temp.size();i++)
		{
			ans=min(ans,temp[i].ff-temp[i-1].ff);
		}
		cout<<dis[n]-ans+1<<endl;
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
