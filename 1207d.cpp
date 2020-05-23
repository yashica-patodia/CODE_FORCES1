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
long long MOD=998244353;
lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli fact[300001];
//lli inv[300001];
void factorial()
{
	lli i;
	fact[0]=1;
	//inv[0]=pwr(fact[0],MOD-2);
	for(i=1;i<=300000;i++)
	{
		fact[i]=(i*fact[i-1])%MOD;
		//inv[i]=pwr(fact[i],MOD-2);
	}
}
bool cmp(pii a,pii b)
{
	return a.ss<b.ss;
}
// A-FIRST ELEMENTS SORTED
// B-2ND ELEMENT IS SORTED
// A INTER B-BOTH ARE SORTED
// A'-FIRST IS NOT SORTED
// B'-2ND ELEMENT IS NOT SORTED
// TO FIND -(A' INTER B')=N(A',B')
// N(A',B')=ALL-UNION(A AND B)


void solve()
{
	factorial();
	int n;
	cin>>n;
	vector<pii> arr(n);
	fr2(i,n)
	cin>>arr[i].ff>>arr[i].ss;
	sort(all(arr));
	lli ans=fact[n];
	lli ans1=1;
	lli ans2=1;
	lli cnt=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i].ff==arr[i-1].ff)
			cnt++;
		else
		{
			ans1=ans1*fact[cnt]%MOD;
		
		cnt=1;
		}

	}
	ans1=ans1*fact[cnt]%MOD;

	ans=(ans-ans1+MOD)%MOD;
	sort(all(arr),cmp);
	 cnt=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i].ss==arr[i-1].ss)
			cnt++;
		else
		{
			ans2=ans2*fact[cnt]%MOD;
		
		cnt=1;
		}

	}
	ans2=ans2*fact[cnt]%MOD;
	ans=(ans-ans2+MOD)%MOD;
	cnt=1;
	lli ans3=1;
	sort(all(arr));
	for(int i=1;i<n;i++)
	{
		if(arr[i].ss<arr[i-1].ss)
		{
			ans3=0;
			break;

		}
		if(arr[i]==arr[i-1])
			cnt++;
		else
		{
			ans3=ans3*fact[cnt]%MOD;
			cnt=1;
		}
	}
	ans3=ans3*fact[cnt]%MOD;
	ans=(ans+ans3+MOD)%MOD;
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
	solve();
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}

