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

struct dsu
{
	vector<lli>par,s;
	vector<vector<int > >cnt;
	lli n;
	lli conn;

	dsu(){}

	dsu(int _n)
	{
		n=_n;
		conn=_n;
		par.assign(n,0);
		s.assign(n,0);
		cnt.resize(n,vector<int>(2,0));
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			s[i]=1;
		}
	}
	lli find(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}
	void merge(lli x,lli y)
	{
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			conn--;
			if(s[x]>=s[y])
			{
				s[x]+=s[y];
				par[y]=x;
				cnt[x][1]+=cnt[y][1];
				cnt[x][0]+=cnt[y][0];
			}
			else
			{
				s[y]+=s[x];
				par[x]=y;
				cnt[y][1]+=cnt[x][1];
				cnt[y][0]+=cnt[x][0];

			}

		}
	}
	lli comp()
	{
		return conn;
	}

};
void solve()
{

	int n,m;
	cin>>n>>m;
	int mat[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	}
	lli ans=0;
	// if(mat[0][0]!=mat[n-1][m-1])
	// 	ans++;
	dsu uf(n+m);
	// for(int k=1;k<=(n+m-2)/2;k++ )
	// {
	// 	int c1=0,c0=0;
	// 	for(int i=0;i<n;i++)
	// 	{
	// 		for(int j=0;j<m;j++)
	// 		{
	// 			if(f==1)
	// 			{
	// 				if(k==((n+m)/2)-1)
	// 					{
	// 						f2=1;
	// 						break;
	// 					}
	// 			}
	// 			if((i+j)==k || (i+j)==n+m-2-k)
	// 			{
	// 				// if(mat[i][j])
	// 				// 	c1++;
	// 				// else 
	// 				// 	c0++;
	// 				if()

	// 			}
	// 		}
	// 		if(f2==1)
	// 			break;
	// 	}
	// 	if(c1>=c0)
	// 		ans+=c0;
	// 	else
	// 		ans+=c1;
	// }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			uf.cnt[i+j][mat[i][j]]++;
	}
	for(int i=0;i<=(n+m-2)/2;i++)
	{
		uf.merge(i,m+n-2-i);
	}
	for(int i=0;i<=(n+m-2)/2;i++)
	{
		if(i==(n+m-2-i))
			continue;
		if(uf.find(i)==i)
		{
			ans+=min(uf.cnt[i][0],uf.cnt[i][1]);

		}
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
