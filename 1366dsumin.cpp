#include<bits/stdc++.h>
using namespace std;     
#define int long long
#define double long double     
typedef vector<int> vi;
typedef vector<vector<int> > Mat;
typedef pair<int, int> pi;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MP make_pair
#define eb emplace_back
#define pb push_back
#define sz(o) (int)o.size()
#define fr(i, n) for(int i=0;i<n;++i)
#define tr(c, it) for(__typeof(c.begin()) it = c.begin();it!=c.end();++it)
#define all(o) o.begin(), o.end()
#define F first
#define S second
#define mset(m, v) memset(m, v, sizeof(m))
#define debug(a) cerr << #a << ": " << a << ' ';
const double PI = 2.0*acos(0);
const int M = 1000000007;
int binpow(int a, int b){if(!b)return 1ll;int temp = binpow(a, b>>1ll);temp = (1ll*temp*temp)%M;if(b&1)temp = (1ll*a*temp)%M;return temp;}

void pre(){

}
class DSU{
public:
	int* rank;int* par;
	int size;
	Mat cnt; //number of elements
	DSU(int n){
		size = n;
		rank = new int[n];par = new int[n];cnt.resize(n, vi(2, 0));
		for(int i=0;i<n;i++){par[i]=i;rank[i]=1;}
	}
	int find(int x){
		if(x==par[x])
			return x;
		else return par[x]=find(par[x]);
	}
	void merge(int x, int y){
		x=find(x);y=find(y);
		if(x==y)
			return;
		if(rank[x] >= rank[y]){
			par[y]=x;
			rank[x]+=rank[y];
			cnt[x][1]+=cnt[y][1];
			cnt[x][0]+=cnt[y][0];
		}
		else{
			par[x]=y;
			rank[y]+=rank[x];
			cnt[y][1]+=cnt[x][1];
			cnt[y][0]+=cnt[x][0];
		}
		size--;
	}
};

void solve(){
	int k,i,j,l,r, n, m;bool flag;
	cin >> n >> m;
	DSU ds(n+m);
	Mat a(n, vi(m));
	fr(i, n){
		fr(j, m)cin>>a[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ds.cnt[i+j][a[i][j]]++;
		}
	}
	for(int i=0;i<=m+n-2;i++)
		ds.merge(i, n+m-2-i);
	int ans=0;
	for(int i=0;i<=(n+m-2);i++){
		int x = ds.find(i);
		if(i==m+n-2-i)
			continue;
		if(x!=i)
			continue;
		else{
			ans += (min(ds.cnt[i][0], ds.cnt[i][1]));
			//debug(i);debug(ds.cnt[i][0]);debug(ds.cnt[i][1]);cout<<'\n';
		}
	}
	cout << ans << '\n';
}
int32_t main(){
    IOS;
    //clock_t begin = clock();
    pre();
    int t,_;cin>>t;_=t;while(t--)//{cout << "Case #" << _ - t << ": ";
    	solve();
    //}
    //clock_t end = clock();double elapsed_secs = (double)(end - begin) / CLOCKS_PER_SEC;cerr<<elapsed_secs<<'\n';
    return 0;
}