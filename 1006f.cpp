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

void calstr(int x,int y,lli val,int cnt);
void calend(int x,int y,lli val,int cnt);

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x);
		x=(x*x);
	}
	return res;
}
int n,m;
lli k,half;
lli ans=0;
lli a[20][20];
map<lli,int> mp[20][20];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	cin>>n>>m;
	//lli k;
	cin>>k;
	
	fr2(i,n)
	{
		fr2(j,m)
		cin>>a[i][j];
	}
	half=(n+m-2)/2;

	calstr(0,0,0,0);
	calend(n-1,m-1,0,0);
	cout<<ans<<endl;
}
void calstr(int x,int y,lli val,int cnt)
{
	val^=a[x][y];
	if(cnt==half)
	{
		++mp[x][y][val];
		return;
	}
	if(x<=n-2)
		calstr(x+1,y,val,cnt+1);
	if(y<=m-2)
		calstr(x,y+1,val,cnt+1);
}
void calend(int x,int y,lli val,int cnt)
{
	if(cnt==(n+m-2-half))
	{
		if(mp[x][y].count(k^val))
			ans+=mp[x][y][k^val];
		return;
	}
	if(x>=1)
		calend(x-1,y,val^a[x][y], cnt+1);
	if(y>=1)
		calend(x,y-1,val^a[x][y],cnt+1);
}	

