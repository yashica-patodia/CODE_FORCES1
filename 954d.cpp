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
int n,m,s,t;
vector<vector<int> >adj;
vector<lli>dis1;
vector<lli>dis2;
//vector<vector<int> >pre;
bool pre[1001][1001];
//queue<int>q;
vector<bool>vis;
vector<lli> bfs(int st)
{
	vector<lli> dis;
	dis.resize(n+1);
	queue<int>q;
//	cout<<st<<endl;
	q.push(st);
	for(int i=1;i<=n;i++)
	{
		vis[i]=false;
		dis[i]=MOD;

	}
	vis[st]=true;
	dis[st]=0;
	int v=q.front();
	//cout<<v<<endl;
	while(!q.empty())
	{
		int u=q.front();
		//cout<<u<<" ";
		//cout<<"y"<<" ";
		q.pop();
		for(auto i:adj[u])
		{
			if(!vis[i])
			{
				vis[i]=true;
				dis[i]=dis[u]+1;
				//cout<<dis[i]<<" ";
				q.push(i);
			}
		}

	}
	return dis;




}
void solve()
{

	cin>>n>>m>>s>>t;
	adj.resize(n+1);
	dis1.resize(n+1);
	dis2.resize(n+1);
	vis.resize(n+1);
	//pre.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].eb(y);
		adj[y].eb(x);
		pre[x][y]=true;
		pre[y][x]=true;
	}
dis1=	bfs(s);
	// for(int i=1;i<=n;i++)
	// 	cout<<dis1[i]<<" ";
dis2=bfs(t);
lli sh=dis1[t];
lli cnt=0;
for(int i=1;i<=n;i++)
{
	for(int j=i+1;j<=n;j++)
	{
		if(!pre[i][j])
		{
			if((dis1[i]+1+dis2[j]>=sh) && (dis2[i]+1+dis1[j]>=sh))
				cnt++;

		}
	}
}
cout<<cnt;

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
