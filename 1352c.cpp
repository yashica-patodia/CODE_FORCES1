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
void solve()
{
	lli n,k;
	cin>>n>>k;
	//vector<lli>v(k+1,0);
	//v[0]=1;
	// lli c=1;
	// lli p=2;
	// while(c!=k)
	// {
	// 	if(p%n==0)
	// 		{ p++;
	// 		continue;
	// 	}
	// 	else
	// 	{
	// 		if(c==k)
	// 		{
	// 			cout<<p<<endl;
	// 			break;
	// 		}
	// 		c++;
	// 		//cout<<c<<" ";
	// 	}
	// 	p++;


	// }
	// cout<<p-1<<endl;
	// lli d=k/(n-1);
	// lli rem=k%(n-1);
	// if(rem==0)
	// 	cout<<d*n-1<<endl;
	// else
	// 	cout<<d*n+rem<<endl;
	// int cnt=p;
	// lli f2=d*n+1;
	// while(cnt<=k)
	// {
	// 	if(f2%n==0)
	// 	{
	// 		f2++;
	// 		continue;
	// 	}
	// 	else
	// 	{
	// 		cnt++;
	// 		if(cnt==k)
	// 		{
	// 			cout<<f2<<endl;
	// 			break;
	// 		}
	// 		f2++;
	// 	}
	// }
	//cout<<f2-1<<endl;
	lli lb=1,ub=2*k;
	lli mm,ans=0;
	while(lb<=ub)
	{
		mm=lb+(ub-lb)/2;
		lli d=mm-mm/n;
		if(d>=k)
		{
			ans=mm;
			ub=mm-1;
		}
		else
			lb=mm+1;
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
