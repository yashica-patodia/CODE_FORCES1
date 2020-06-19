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
vector<vector<int> >adj;
int  n,m,a,b,c;
vector<lli>cost;
set<int>st;
set<int>st2;
void bfs(int start)
{
	//set<int>st;
	queue<int>q;
	q.push(start);
	//bool vis[n+1]=false;
	vector<bool>vis(n+1,false);
	st.insert(start);
	vis[start]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto i:adj[u])
		{
			if(!vis[i])
			{
				vis[i]=true;
				q.push(i);
				st.insert(i);
				if(i==b)
					return ;

			}
		}
	}



}
void bfs2(int start)
{
	//set<int>st;
	queue<int>q;
	q.push(start);
	//bool vis[n+1]=false;
	vector<bool>vis(n+1,false);
	st2.insert(start);
	vis[start]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto i:adj[u])
		{
			if(!vis[i])
			{
				vis[i]=true;
				q.push(i);
				st2.insert(i);
				if(i==c)
					return ;

			}
		}
	}



}
void solve()
{
	cin>>n>>m>>a>>b>>c;
	cost.resize(m);
	adj.resize(n+1);
	fr2(i,m)
	cin>>cost[i];
	fr2(i,m)
	{
		int u,v;
		cin>>u>>v;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	//set<int>s;
	///vector<int>pre;
	//pre.resize(n);
	bfs(a);
	bfs2(b);
	for(auto i:st)
		cout<<i<<" ";
	for(auto i:st2)
		cout<<i<<" ";
	sort(all(cost));
	int cnt=0;
	if(st.size()<=st2.size())
{
	auto it=st.begin();
	auto it2=st2.begin();
	
	for(auto i=it;i!=st.end();i++,it2++)
	{
		if(*i==*it2)
			cnt++;
	}
}
else
{
	auto it=st.begin();
	auto it2=st2.begin();
	
	for(auto i=it2;i!=st2.end();i++,it++)
	{
		if(*i==*it)
			cnt++;
	}

}
int tot=st.size()+st2.size()-2*cnt;
lli ans=0;
int k=0;
for(int i=0;i<cnt &&  k<m;i++)
{
	ans+=2*cost[k++];
}
for(int i=0;i<tot && k<m;i++)
{
	ans+=cost[k++];
}
cout<<ans<<endl;

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
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();

	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
