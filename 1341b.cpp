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
bool issafe(lli crow,lli ccol,lli prow,lli pcol);
void ways(lli rows,vector<lli> &prev);
void display(vector<lli> &prev);

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
int n;
lli ans=0;
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
		lli n,k;
		cin>>n>>k;
		lli a[n+1];
		fr(i,n)
		{
			cin>>a[i];
		}
		lli p[n+2];
		p[0]=0;
		//p[1]=0;
		inc(i,1,n-2)
		{
			if(a[i]>a[i-1] && a[i]>a[i+1])
				p[i]=p[i-1]+1;
			else
				p[i]=p[i-1];
		}
		p[n-1]=p[n-2];
		lli pe;
		lli mx=INT_MIN;
		lli index=0;
		// fr2(i,n)
		// cout<<p[i]<<" ";
		// f;
		for(lli i=0;i<=n-k;i++)
		{
			// if(i==0)
			// 	pe=p[k-2]-pe[i];
			// else
			// {
				// if(a[i]>a[i-1] && a[i]>a[i+1])
				// 	f=1;
				// else
				// 	f=0;
				pe=p[i+k-2]-p[i];
			//}
			//cout<<pe<<" ";
			if(pe>mx)
			{
				mx=pe;

				 index=i;
				 //cout<<mx<<" "<<index<<" ";

			}


		}
		cout<<mx+1<<" "<<index+1<<endl;

	}
}