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
lli n,q,f1,f2,a,b,l,r;
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	// clock_t start,end;
	// start=clock();
	
	
	
	
		
		cin>>n>>q>>f1>>f2>>a>>b;
		vector<lli>vec;
		vec.resize(n);
		
		for(int j=0;j<n;j++)
			cin>>vec[j];
		lli pre[n+3]={0};
		pre[0]=0;
		lli ff[n+3]={0};
		ff[1]=f1;
		ff[2]=f2;
		for(lli i=3;i<=(n+2);i++)
		{
			ff[i]=(a*ff[i-2]+b*ff[i-1])%MOD;
		}

		//for()
		for(int i=0;i<q;i++)
		{
			cin>>l>>r;
			
			pre[l]=(pre[l]+ff[1])%MOD;
			//pre[l]=pre[l]%MOD;
			pre[l+1]= (pre[l+1]+ff[2]-b*ff[1]+MOD)%MOD;
			pre[r+1]=(pre[r+1]-ff[r-l+2]+MOD)%MOD;
			pre[r+2]=(pre[r+2]-a*ff[r-l+1]+MOD)%MOD;
			for(int i=2;i<=n;i++)
				cout<<pre[i-2]*a+pre[i-1]*b<<" ";
			cout<<endl;

				//solve();
		}
		lli pre2[n+3]={0};
		pre2[1]=ff[1];
		//pre2[2]=ff[2];
		for(lli i=2;i<=n+2;i++)
		{
			pre2[i]=(a*pre[i-2]+b*pre[i-1])%MOD;
		}
		// for(lli i=1;i<=n;i++)
		// 	cout<<(vec[i-1]+pre2[i])%MOD<<" ";
		// cout<<endl;


	

	
}
