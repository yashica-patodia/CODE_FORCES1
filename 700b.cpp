#include<bits/stdc++.h>
using namespace std;   //author: madmin2619/mintu_agarwal
     
#define nfs() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl '\n'
#define pb push_back
#define pf push_front
#define eb emplace_back
#define debug(x) cerr << #x << ": " << x << '\n';
#define forin(i, n) for(int i=0;i<n;i++)
#define tr(c, it) for(auto it=c.begin();it!=c.end();it++)
#define sz(c) (int)c.size()
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define m_p(x, y) make_pair(x, y)
#define mem(v, val) memset(v, val, sizeof(v))

typedef vector<vector<int> > Mat;
typedef pair<int, int> pi;
     
const int M = 1e9 + 7;
const int N = 2e5+5;
bool vis[N];
int subs[N];
bool col[N];
Mat adj;
int ans, k;
void pre(){

	return;
}
void dfs(int u){
	vis[u]=1;
	for(auto x:adj[u]){
		if(!vis[x]){
			dfs(x);
			subs[u]+=subs[x];
		}
	}
	if(col[u])
		subs[u]++;
	ans += min(subs[u], 2*k-subs[u]);
}
void solve(){
	int n, i, j, m;
	cin >> n >> k;
	adj.resize(n+1);
	forin(i, 2*k){cin>>j; col[j]=1;};
	forin(i, n-1){
		cin >> j >> m;
		adj[j].eb(m);
		adj[m].eb(j);
	}
	dfs(1);
	ans -= min(2*k-subs[1], subs[1]);
	cout << ans << '\n';
	return;
}

int32_t main(){
    nfs()
    pre();
    //long long t;cin >> t;while(t--)
        solve();
    return 0;
}