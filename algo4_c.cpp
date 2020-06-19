//dp(i,j) represents taking i length and j being the last maximum index
//// dp(i,j)=dp(i-1)(j)//not choose j
//dp(i,j)=dp(i-1,j-1)*cnt(postion i pe jo character hai S mein how many times does that occur in all strings at position j)
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
long long MOD=1000000007;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
void solve()
{
	lli n;
	cin>>n;
	vector<string>v(n);
	lli mx=0;
	fr(i,n)
	{
	cin>>v[i];
	mx=max(mx,1LL*(v[i].length()));
	}
	string str;
	cin>>str;
	// if(n==1)
	// {
		
	// }
	lli nn=str.length();
	lli cnt[26][mx+1];
	mset(cnt,0);
	
		for(lli j=0;j<n;j++)
		{
			for(lli k=0;k<v[j].length();k++)
			{
				cnt[v[j][k]-'a'][k]++;

			}


		}
		// for(int i=0;i<26;i++)
		// {
		// 	for(int j=0;j<mx;j++)
		// 		cout<<cnt[i][j]<<" ";
		// 	cout<<endl;

		// }
		//cout<<mx<<endl;

	lli dp[nn+1][mx+1];
	mset(dp,0);
	for(lli i=0;i<=mx;i++)
		dp[0][i]=1;
	// for(lli i=1;i<=nn;i++)
	// {
	// 	dp[i][0]=0;
	// }
	for(lli i=1;i<=nn;i++)
	{
		for(lli j=1;j<=mx;j++)
		{
			//dp[i][j]=dp[i][j-1]%MOD;
			////dp[i][j]+=(1LL*dp[i-1][j-1]*cnt[str[i-1]-'a'][j-1])%MOD;
			//dp[i][j]%=MOD;
			dp[i][j]=(dp[i][j-1]%MOD+((dp[i-1][j-1]%MOD)*(cnt[str[i-1]-'a'][j-1]%MOD)%MOD))%MOD;
		}
	}
	// for(lli i=0;i<=nn;i++)
	// {
	// 	for(lli j=0;j<=mx;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<dp[nn][mx]<<endl;



	

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
