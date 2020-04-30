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
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		lli i;
		lli arr[n+1];
		for(i=0;i<n;i++)
			cin>>arr[i];
		lli sum=0,x,y;
		//int cnt=0;
		for(i=0;i<n;)
		{
			x=0;
			while(i<n && arr[i]>0)
			{
				ymax(x,arr[i]);
				i++;
			}
			if(x>0)
				sum+=x;
			if(i==n)
				break;
			y=LLONG_MIN;
			while(i<n && arr[i]<0)
			{
				ymax(y,arr[i]);
				//cout<<y<<" ";
				i++;
			}
			if(y!=LLONG_MIN)
				sum+=y;


			
			//msum=max(sum,msum);


		}
		cout<<sum<<endl;
		
	}
}


