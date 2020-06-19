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
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
	int n;
	cin>>n;
	vector<pair<int,int>>v;
	int arr[n];
	fr2(i,n)
	{
		int x;
		cin>>x;
		arr[i]=x;
		//v.pb({x,i});
	}
	if(n<=2)
	{
		cout<<"no";
		//return ;
	}
	else
	{
	for(int i=0;i<n-1;i++)
	{
		v.pb({arr[i],arr[i+1]});
	}
	int f=0;
	for(int i=0;i<n-2;i++)
	{
		int x1=v[i].ff;
		int x2=v[i].ss;
		for(int j=i+1;j<n-1;j++)
		{
			int y1=v[j].ff;
			int y2=v[j].ss;
			if(x1<y1 && y1<x2 && x2<y2)
			{
				f=1;
				break;
			}
		else	if(x1<y2 && y2<x2 && x2<y1)
			{
				f=1;
				break;
			}
			else if(y1<x1 && x1<y2 && y2<x2)
			{
				f=1;
				break;
			}
			else if(y1<x2 && x2<y2 && y2<x1)
			{
				f=1;
				break;
			}
			else if(x2<y2 && y2<x1 && x1<y1)
			{
				f=1;
				break;
			}


		}
		// int x1=v[i].ff;
		// int x2=v[i].ss;
		// int y1=v[i+1].ff;
		// int y2=v[i+1].ss;
		// if()


	}
	if(f==0)
		cout<<"no";
	else
		cout<<"yes";
	
// 	sort(all(v));
// 	int f=1;
// 	for(int i=1;i<n;i++)
// 	{
// 		if(v[i].ss>v[i-1].ss)
// 		{
// 			continue;
// 		}
// 		else
// 		{
// 			f=0;
// 			break;
// 		}

// 	}
// 	if(f==1)

// 		cout<<"no";
// 	else
// 	{
// 		int d=arr[1]-arr[0];
// 		for(int i=2;i<n;i++)
// 		{
// 			if(arr[i]-arr[i-1])
// 		}
// 	}
	
// }
}}