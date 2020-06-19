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
void solve()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(n*a!=m*b)
	{
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	//int d=a/b;
	// int gap=0;
	// //int mat[60][60];
	 vector<vector<int> >mat(n,vector<int>(m,0));
	// for(int i=0;i<n;i++)
	// {
	// 	gap++;
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		if(j>=(gap-1)*d && j<(gap)*d)
	// 			cout<<1;
	// 		else
	// 			cout<<0;


	// 	}
	// 	cout<<endl;
	// }
	 int d;
	 for(int i=1;i<m;i++)
	 {
	 	if((i*n)%m==0)
	 	{
	 		d=i;
	 		break;
	 	}
	 }
//	int d=i;
	for(int i=0,dx=0;i<n;i++,dx+=d)
	{
		for(int j=0;j<a;j++)
		{
			mat[i][(j+dx)%m]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<mat[i][j];
		cout<<endl;
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
