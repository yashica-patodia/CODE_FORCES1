// for(int i=2;i<=n;i++)
// 	par[i]=p[i-2];
// /Linearity of expectation --
// EX(ax+by)=a*E(x)+b*E(y)

// expectation is similar to mean 
// summation of p(i)*(i);
// V(x,i)--> i will  come before x
// this is one if i comes before x and 0 if not
 
// Let us define a function pos(x) in a sequence
// pos(x)=V(x,1)+V(x,2)+V(x,3)....

// we will take expectation on both sides using linearity of expectations?
// case 1-->node i is parent of x then V(X,i)=1
// CASE 2--->I==X v(x,i)=0
// case 3--->i is in subtree of x then V(x,i)=0
// CASE4----> I is in a subtree of parent of x V(x,i)=0.5

// FOR CASE 1  AISE KITNE NODES HAI??
// LEVEL(X) KYUKI AGAR USKA LEVEL 3 THEN 3 PARENT HONGE(ANCESTORS) LEVEL OF ROOT 0

// CASE 4--->
// TOTAL NODES=N
// SUBTREE MEIN MANO SZ(X)
// TOH TOTAL NODES IN CASE 4--->(N-SZ(X)-LEVEL(X))

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
vector<int>s;
vector<int>lev;
//vector<int>vis;
int n;
void dfs(int v,int l,int par)
{
	lev[v]=l;
	s[v]=1;
	for(auto i:adj[v] )
	{
		if(i!=par)
		{
			dfs(i,l+1,v);
			s[v]+=s[i];
		}
	}
}
void solve()
{
	cin>>n;
	adj.resize(n+1);
	s.resize(n+1);
	lev.resize(n+1);


	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		adj[i].eb(p);
		adj[p].eb(i);

	}

	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<s[i]<<" "<<lev[i]<<endl;
	double f=1;
	cout<<fixed<<setprecision(6)<<f<<" ";
	double ans=0;
	for(int i=2;i<=n;i++)
	{
		ans=(n-s[i]-lev[i])/2.0 +lev[i]+1.0;
		cout<<fixed<<setprecision(6)<<ans<<" ";


	}
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
