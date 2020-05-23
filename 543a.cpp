#include <bits/stdc++.h>
using namespace std;
  
typedef long long int ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
  
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)

ll n,m,b,mod,ans=0;

// void solve()
// {

// }
ll dp[501][501];
ll a[501];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m>>b>>mod;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 0; k <= b; ++k)
			{
				if(k>=a[i])
				{
					dp[j][k]+=dp[j-1][k-a[i]];
					dp[j][k]=dp[j][k]%mod;
				}
			}
		}
		for(int j1=0;j1<=m;j1++)
		{
			for(int k1=0;k1<=b;k1++)
				cout<<dp[j1][k1]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	for (int i = 0; i <= b; ++i)
	{
		ans+=dp[m][i];
		ans%=mod;
	}
	cout<<ans<<endl;
}