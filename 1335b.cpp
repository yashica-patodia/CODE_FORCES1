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
	int n,a,b;
	cin>>n>>a>>b;
	// string str="";
	// string str2="";
	// for(int i=0;i<b;i++)
	// {
	// 	str=str+(char)('a'+i);
	// 	str2=(char)('a'+i)+str2;
	// }
	// cout<<str<<" "<<str2<<endl;
	// string ans="";
	// for(int i=0;i<=n-a;)
	// {
	// 	ans=ans+str;
	// 	i=i+b-1;
	// 	int k=0;
	// 	while(k<(a-b))
	// 	{
	// 		k++;
	// 		ans[k+i]=str2[k-1];
	// 	}
	// 	i=i+(a-b)+1;


	// }
	string str="abcdefghijklmnopqrstuvwxyz";
		//lli n,a,b,i;
		//cin>>n>>a>>b;
		//char ch[n+1];
		string ans;
		lli d=n/b;
		lli rem=n%b;
		for(int i=0;i<d;i++)
			ans+=str.substr(0,b);
		ans+=str.substr(0,rem);
		cout<<ans<<endl;
	//cout<<ans<<endl;
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
	
	
// 	end=clock();
	
// 	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
// 	cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
// }
}
