#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define fo(i,n) ll i;for(i=1;i<=n;i++)
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define ppi pair<Sint,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}


ll dp[100001][5];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    IOS
    
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vll v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];

    string str="hard";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=4;j++)
            dp[i][j]=1e14;
    }
    dp[0][0]=0;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<4;j++)
        {
            if(s[i]==str[j])
            {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            }
            else
            {
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            }
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+v[i]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=4;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    ll ans=1e18;
    for(int i=0;i<4;i++)
    {
        //cout<<dp[n][i]<<endl;
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<endl;

    return 0;
}