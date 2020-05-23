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
vector<int> init(200001);
vector<int> pos(200001);
bool cmp(int a,int b)
{
	return pos[a]<pos[b];
}
void solve()
{
	int n;
	cin>>n;
//	cout<<n;
	map<int,vector<int>>adj;
	fr2(i,n-1)
	{
		int u,v;
		cin>>u>>v;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	init.resize(n+1);
	pos.resize(n+1);
	
	for(int i=0;i<n;i++)
	{
		//int x;
		cin>>init[i];
		//cout<<init[i]<<endl;;
		pos[init[i]]=i;
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<pos[i]<<" ";
	for(int i=1;i<=n;i++)
		sort(all(adj[i]),cmp);
	queue<int>q;
	vector<bool>vis(n+1,false);
	q.push(1);

	vector<int>ans;
	//ans.eb(1);
	vis[1]=true;
	while(!q.empty())
	{
		int st=q.front();
		ans.eb(st);
		q.pop();
		for(auto j:adj[st])
		{
			if(!vis[j])
			{
				q.push(j);
				vis[j]=true;
			}
		}


	}
	int f=1;
	for(int i=0;i<n;i++)
	{
		if(ans[i]!=init[i])
		{
			f=0;
			cout<<"NO"<<endl;
			break;
		}
	}
	if(f==1)
		cout<<"YES"<<endl;
	

}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	clock_t start,end;
	start=clock();
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	//cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	solve();

	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
