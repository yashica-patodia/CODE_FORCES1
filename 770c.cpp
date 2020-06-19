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
int n,k;
vector<vector<int>>adj;
vector<int>col;
vector<int>topo;
vector<int>cour;
void dfs(int v)
{
	col[v]=1;
	for(auto i:adj[v])
	{
		if(col[i]==0)
			dfs(i);
		else if(col[i]==1)
		{
			cout<<-1<<endl;
			exit(0);
		}
	}
	col[v]=2;
	topo.eb(v);

}
void solve()
{
	cin>>n>>k;
	adj.resize(n+1);
	//in.assign(n+1,0);
	cour.resize(k);
	col.assign(n+1,0);
	topo.clear();
	for(int i=0;i<k;i++)
	{
		cin>>cour[i];

	}
	// vector<vector<int> >adj2;
	// adj2.resize(n+1);
	// for(int i=1;i<=n;i++)
	// {
	// 	int tt;
	// 	cin>>tt;
	// 	for(int j=1;j<=tt;j++)
	// 	{
	// 		int p;
	// 		cin>>p;
	// 		//adj[p].eb(i);
	// 		adj2[i].eb(p);
	// 		in[p]++;
	// 	}
	// }
	// queue<int>pq;
	// for(int i=1;i<=n;i++)
	// {

	// 	if(in[i]==0)
	// 		pq.push(i);
	// }
	// while(!pq.empty())
	// {
	// 	int v=pq.front();
	// 	pq.pop();
	// 	topo.eb(v);
	// 	for(auto j:adj[v])
	// 	{
	// 		in[j]--;
	// 		if(in[j]==0)
	// 			pq.push(j);
	// 	}
	// }
	// if(topo.size()!=n)
	// {
	// 	cout<<-1<<endl;
	// 	return;
	// }
	// else
	// {
	// 	for(auto i:topo)
	// 	{
	// 		//if(i)
	// 		cout<<i<<" ";
	// 	}
	// 	cout<<endl;
	// // 	vector<bool>vis(n+1,false);
	// // 	for(int i=0;i<k;i++)
	// // 	{
	// // 		vis[cour[i]]=true;
	// // 		for(auto j:adj2[cour[i]])
	// // 		{
	// // 			vis[j]=true;
	// // 		}
	// // 	}
	// // 	lli cnt=0;
	// // 	for(int i=1;i<=n;i++)
	// // 	{
	// // 		if(vis[i])
	// // 			cnt++;

	// // 	}
	// // 	cout<<cnt<<endl;
	// // 	for(int i=1;i<=n;i++)
	// // 	{
	// // 		if(vis[i])
	// // 			cout<<i<<" ";
	// // 	}
	// // 	cout<<endl;
	// }
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=p;j++)
		{
			int v;
			cin>>v;
			adj[i].eb(v);
		}
	}
	for(int i=0;i<k;i++)
	{
		//cout<<cour[i]<<endl;
		if(col[cour[i]]==0)
			dfs(cour[i]);
	}
	cout<<topo.size()<<endl;
	for(auto i:topo)
		cout<<i<<" ";
	cout<<endl;



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
