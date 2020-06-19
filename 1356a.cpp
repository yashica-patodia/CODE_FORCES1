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
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
void solve()
{
	int n,x;
	cin>>n>>x;
	vector<lli>v(n);
	fr2(i,n)
	cin>>v[i];
	lli pre[n+1]={0};
	pre[0]=0;

	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+v[i-1];
		pre[i]%=x;
	}
	// int f=1;
	// int l=0;
	// lli ans=-1;
	// for(int i=n;i>=1;i--)
	// {
		// l=0;
		// if((pre[i]-pre[l])%x!=0)
		// {
		// 	ans=max(ans,1LL*(i-l));
		// 	cout<<ans<<endl;
		// 	f=1;
		// 	//continue;
		// 	return;
		// }
		// else
		// {
		// 	l++;
		// 	while(l<i)
		// 	{

		// 		if((pre[i]-pre[l])%x!=0)
		// 		{
		// 			ans=max(ans,1LL*(i-l));
		// 			//cout<<i-l<<endl;
		// 			//f2=1;
		// 			break;

		// 		}
		// 		l++;
		// 	}

		// }
		//if()

	//}	
			int r=n,l=0;
			lli ans=-1;
			while(r>l)
			{
				if(pre[r]!=pre[l] && (pre[r]-pre[l]+x)%x!=0)
				{
					ans=max(ans,1LL*r-l);
					r--;
					continue;
					//cout<<r-l<<endl;
					//return;
				}
				while(r>l && pre[r]==pre[l])
				{
					l++;

				}
				if(r!=l)
				ans=max(ans,1LL*r-l);
				r--;
			}
			if(ans!=-1)
				cout<<ans<<endl;
			else
			cout<<-1<<endl;

// 	if(ans==-1)
// 	cout<<-1<<endl;
// else
// 	cout<<ans<<endl;
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
