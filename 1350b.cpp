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
const int N=1000001;
lli lpf[N]={0};
void seive()
{
	lpf[1]=1;
	for(lli i=2;i<N;i++)
	{
		if(lpf[i]==0)
		{
			lpf[i]=i;
			for(lli j=2*i;j<N;j+=i)
				if(lpf[j]==0)
					lpf[j]=i;
		}
	}
}
void solve()
{
	int n;
	cin>>n;
	//vector<lli>ft;
	//set<lli>st;
//map<lli,lli>mp;
	lli s[n+1];
	for(int i=1;i<=n;i++)
		cin>>s[i];
	// while(n>1)
	// {
	// 	ft.eb(n);
	// 	lli temp=lpf[n];
	// 	lli temp2=n;
	// 	while(temp2%temp==0)
	// 	{
	// 		temp2=temp2/temp;
	// 		temp=lpf[temp2];
	// 	}
	// }

// 	while(n!=1)
// 	{
// 		st.insert(lpf[n]);
// 		//mp[k++]=lpf[n];
// 		n=n/lpf[n];
// 		//lli tp=lpf[n];


// 	}

// }
	// ft.eb(s[1]);
	// //lli j=1;
	// while(lpf[n]==n)
	// {
	// 	--n;
	// }
	// //cout<<n<<endl;
	// lli tp=lpf[n];
	// lli cnt=0;
	// for(lli i=tp;i<=n;i++)
	// {
	// 	//ft.eb(i);
	// 	if(n%i==0)
	// 	{
	// 	// if(s[i]>s[j])
	// 	// 	cnt+=2;
	// 	// j=i;
	// 	// }
		
	// 	// }
	// 		ft.eb(s[i]);
	// 	}
	// 	//cout<<cnt<<endl;
	// }
	// for(auto i:ft)
	// 	cout<<i<<" ";
	// vector<lli>dp(sz(ft));
	// dp[0]=1;
	// for(lli i=1;i<sz(ft);i++)
	// {
	// 	dp[i]=1;
	// 	for(lli j=0;j<i;j++)
	// 	{
	// 		if(ft[i]>ft[j] && dp[i]<(dp[j]+1) )
	// 			dp[i]=dp[j]+1;
	// 	}
	// }
	// cout<<*max_element(all(dp))<<endl;
	// for(lli i=1;i<=n;i++)
	// {

	// }
	//int j=1;
	lli cnt=1;
	for(int j=1;j<=n;j++)
	{
	for(int i=j+1;i<=n;i++)
	{
		if(i%j==0 && s[i]>s[j])
		{
			cnt++;
			j=i;
		}
		
	}
}
	cout<<cnt<<endl;
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
	//seive();
	for(int i=1;i<=t;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();

	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}