#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin, (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;

typedef vector<plli> vplli;
long long MOD=1000000009;
int check(int mm,int k,int n,int dp[],string str);
int main()
 {
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	int dp[n+1];
	fr2(i,n)
	{
		if(str[i]=='0')
			dp[i+1]=1;
		else
			dp[i+1]=0;

	}
	dp[0]=0;
	fr(i,n)
	{
		dp[i+1]+=dp[i];
	}
	int lb=0,ub=n+1,mm,ans=n+1;
	while(lb<=ub)
	{
		mm=lb+(ub-lb)/2;
		if(check(mm,k,n,dp,str))
		{
			ans=mm;
			ub=mm-1;

		}
		else
			lb=mm+1;
	}
	cout<<ans<<endl;

	
}
int check(int mm,int k,int n,int dp[],string str)
{
	inc2(i,1,n)
	{
		if(str[i-1]=='1')
			continue;
		int left=max(1,i-mm);
		int right=min(n,i+mm);
		if(dp[right]-dp[left-1]>=k+1)
		{
			return 1;
		}

	}
	return 0;
}
