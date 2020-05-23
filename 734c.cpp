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
lli n,m,k;
lli x,s;
lli a[200001],b[200001],c[200001],d[200001];
lli bs(lli mn)
{//cout<<mn<<endl;
	lli lb=0,ub=k-1,ans=0;
	if(mn<d[0])
		return 0;
	//cout<<d[0]<<endl;
	while(lb<=ub)
	{
		lli mm=lb+(ub-lb)/2;
		//if(mm<k)
		//{
		if(  d[mm]<=mn)
		{
			ans=mm;
			lb=mm+1;
		}
		else
			ub=mm-1;
	//}
	}
	//cout<<c[ans]<<endl;
	return c[ans];
}
void solve()
{
	
	cin>>n>>m>>k;
	
	cin>>x>>s;
	
	for(lli i=0;i<m;i++)
		cin>>a[i];
	for(lli i=0;i<m;i++)
		cin>>b[i];
	for(lli i=0;i<k;i++)
		cin>>c[i];
	for(lli i=0;i<k;i++)
		cin>>d[i];
	lli ans=n*x;
	lli left=s;
	lli p=bs(left);
	lli ans2=(x*(n-p));
	ans=min(ans,ans2);
	for(lli i=0;i<m;i++)
	{
		lli left=s-b[i];
		if(left<0)
			continue;
		else
		{
			ans=min(ans,(n-bs(left))*a[i]);

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
