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
vector<pair<int,pair<int,int>>>adj;
vector<int>par;
vector<int>s;
vector<pair<lli,int>>q;
vector<lli>res;
int n,m;
lli ans=0;
void init()
{//scout<<"hi";
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		s[i]=1;
	}
}
int find(int v)
{
	while(par[v]!=v)
	{
		par[v]=par[par[v]];
		v=par[v];
	}
	return v;

}

void solve()
{
	cin>>n>>m;
	//adj.resize(n);
	if(n==1)
	{
		for(int i=0;i<m;i++)
			cout<<0<<" ";
		cout<<endl;
		return;
	}
	par.assign(n+1,-1);
	s.assign(n+1,0);
	q.resize(m);
	res.resize(m);
	init();
	for(int i=0;i<n-1;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj.pb({w,{u,v}});
	}
	for(int i=0;i<m;i++)
	{
		lli p;
		cin>>p;
		q[i]={p,i};
	}
	sort(all(adj));
	sort(all(q));
	int j=0;
	for(int i=0;i<m;i++)
	{

		//int j=0;
		//cout<<j<<" "<<i<<endl;
		//cout<<adj[j].ff<<" "<<q[i].ff<<endl;
		while(j<n-1 && adj[j].ff<=q[i].ff)
		{
			int x=adj[j].ss.ff;
			int y=adj[j].ss.ss;
			int r1=find(x);
			int r2=find(y);
			lli o1=s[r1];
			lli o2=s[r2];
			//cout<<x<<" "<<y<<" "<<r1<<" "<<r2<<" "<<o1<<" "<<o2<<endl;
			if(r1!=r2)
			{
				if(s[r1]>=s[r2])
				{
					s[r1]+=s[r2];
				//	s[r2]=0;
					par[r2]=r1;
				}
				else
				{
					s[r2]+=s[r1];
					//s[r1]=0;
					par[r1]=r2;
				}
			//	ans+=(1LL*(o1*o2*1LL));
				ans+=(((o1+o2)*(o1+o2-1)/2)-(o1*(o1-1)/2)-(o2*(o2-1)/2));
				
			}

				//cout<<ans<<" "<<j<<endl;
			j++;
		}
		res[q[i].ss]=ans;
		//cout<<ans<<endl;
		//cout<<res[q[i].ss]<<endl;
		//ans=0;

	}
	for(auto i:res)
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
