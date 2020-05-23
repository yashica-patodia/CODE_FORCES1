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
lli dp[1001][1001];
void solve()
{
	int n;
	cin>>n;
	vector<int>v(n+1,0);
	fr2(i,n)
	cin>>v[i];
	//vector<vector<
	fr2(i,n)
	dp[i][i]=1;
	for(int i=0;i<n-1;i++)
	{
		if(v[i]==v[i+1])
			dp[i][i+1]=1;
		else
			dp[i][i+1]=2;
	}
	for(int gap=3;gap<=n;gap++)
	{
		for(int i=0;i<=n-gap;i++)
		{
			int j=i+gap-1;
			// if(v[i]==v[j] && dp[i+1][j-1])
			// 	dp[i][j]=1;
			// else
			// {
			 	dp[i][j]=min(1+dp[i+1][j],1+dp[i][j-1]);
				if(v[i]==v[j])
					dp[i][j]=dp[i+1][j-1];
				if(v[i]==v[i+1])
					ymin(dp[i][j],dp[i+2][j]+1);
				if(v[j]==v[j-1])
					ymin(dp[i][j],dp[i][j-2]+1);
				for(int p=i+2;p<j;p++)
				{
					if(v[p]==v[i])
						ymin(dp[i][j],dp[i+1][p-1]+dp[p+1][j]);

				}
				for(int p=j-2;p>i;p--)
				{
					if(v[p]==v[j])
						ymin(dp[i][j],dp[i][p-1]+dp[p+1][j-1]);
				}
			}

		//}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<dp[0][n-1]<<endl;



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
	solve();
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
