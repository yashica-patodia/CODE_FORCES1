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
lli pwr(lli x ,lli n)
{
	lli res=1;
	for(;n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x);
		x=(x*x);

	}
	return res;
}
// lli pwr(lli x,lli n)
// {
// 	lli res=1;
// 	for(; n!=0;n>>=1)
// 	{
// 		if(n&1)
// 			res=(res*x)%MOD;
// 		x=(x*x)%MOD;
// 	}
// 	return res;
// }
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
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length();
	int q=0,des=0,cov=0;
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='+')
			des+=1;
		else
			des-=1;
	}
	for(int i=0;i<n;i++)
	{
		if(s2[i]=='?')
		{
			q++;
			//cout<<q<<" "<<i<<endl;
		}
		else if(s2[i]=='+')
			cov+=1;
		else 
			cov-=1;

	}
	if(q==0 && des==cov)
	{
		cout<<fixed<<setprecision(12)<<1.0<<endl;
		return 0;
	}
	if(q==0 && des!=cov)
	{
		cout<<fixed<<setprecision(12)<<0.0<<endl;
		return 0;
	}

	//cout<<q<<endl;
	lli p=pwr(2,q);
	// cout<<p<<endl;
	// cout<<q<<endl;
	lli yp=0;
	for(lli i=0;i<(1<<q);i++)
	{
		lli temp=0;
		for(lli j=0;j<q;j++)
		{
			if(i&(1<<j))
				temp+=1;
			else
				temp-=1;

		}
		// cout<<temp<<" "<<i<<endl;
		// cout<<des<<" "<<cov<<" "<<temp<<endl;
		if(temp+cov==des)
			yp++;
	}
	//cout<<yp<<endl;
	double ans=(yp*1.0)/(p*1.0);
	// double lk=(1.0/8);
	// cout<<lk<<endl;
	cout<<fixed<<setprecision(12)<<ans<<endl;
}
