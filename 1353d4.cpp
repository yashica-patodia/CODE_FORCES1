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
struct cmp{
bool operator() (const pair<int,int> &a, const pair<int,int> &b) const{

	int l1=a.ss-a.ff+1;
	int l2=b.ss-b.ff+1;
	if(l1==l2)
		return a.ff<b.ff;
	return l1>l2;
}};
void solve()
{
	int n;
	cin>>n;
	// vector<int>arr(n+1,0);
	// //int arr[n+1]={0};
	// set<pair<int,int>,cmp>st;
	// st.insert(make_pair(1,n));
	// int cnt=0;
	// int n2=n;
	// while(n2--)
	// {
	// 	auto it=st.begin();
	// 	///if(it.ff-it.ss+1>0)
	// 	//{
	// 	//cout<<it->ff<<" "<<it->ss<<" ";
	// 		int m=(it->ff+it->ss)/2;
	// 		//cout<<m<<" ";
	// 		arr[m]=++cnt;
	// 		//cout<<arr[m]<<" ";
	// 		if(m-it->ff)
	// 		st.insert(make_pair(it->ff,m-1));
	// 		if(it->ss-m)
	// 		st.insert(make_pair(m+1,it->ss));
	// 	st.erase(it);

	// 	//}

	// }
	// for(int i=1;i<=n;i++)
	// 	cout<<arr[i]<<" ";
	// cout<<endl;
	int arr[n+1]={0};
	set<pair<int,pair<int,int> > >s;
	s.insert({-n,{1,n}});
	int curr=0;
	while(s.size())
	{
		++curr;
		auto p=*s.begin();
		s.erase(p);
		int l=p.ss.ff,r=p.ss.ss;
		int m=(l+r)/2;
		arr[m]=curr;
		if(m-l)
			s.insert({-(m-l),{l,m-1}});
		if(r-m)
			s.insert({-(r-m),{m+1,r}});

	}
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
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
