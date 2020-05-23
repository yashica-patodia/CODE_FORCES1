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
const int N=1000001;
//const lli N=1000001;
//lli fact[N];
lli lpf[N]={0};
void seive()
{
	lpf[1]=1;
	for(lli i=2;i<N;i++)
	{
		if(lpf[i]==0)
		{
			lpf[i]=i;
			for(lli j=2*i;j<N;j+=i)
				if(lpf[j]==0)
					lpf[j]=i;
		}
	}
}

void solve()
{
	int n;
	cin>>n;
	lli arr[n];
	lli p=1e15;
	fr2(i,n)
	{

	cin>>arr[i];
	p=min(p,lpf[arr[i]]);
}
	// sort(arr,arr+n);
	// lli mil=1e15;
	// //lli c=0;
	// //vector<lli>v;
	// lli res=(arr[0]*arr[1])/__gcd(arr[0],arr[1]);
	// for(int i=0;i<n-1;i++)
	// {
	// 	// if(arr[i]*arr[i]>mil)
	// 	// 	break;
		
	// 	for(int j=i+1;j<n;j++)
	// 	{
	// 		// if(arr[i]*arr[j]>mil)
	// 		// 	break;
	// 		//else

	// 		lli tp=(arr[i]*arr[j])/__gcd(arr[i],arr[j]);
	// 		res=__gcd(res,tp);
	// 		//cout<<tp<<endl;
	// 		//v.eb(tp);
	// 		//c++;
	// 			//mil=min(mil,tp);
	// 	}
	// }
	//cout<<c<<endl;
	sort(arr,arr+n);
	lli res=arr[0];
	for(int i=1;i<n;i++)
	{
		res=__gcd(arr[i],res);
		if(res==1)
		{
			res=1;
			//cout<<1<<endl;
			break;
		}
	}

	//cout<<v[0]<<" "<<v[1]<<endl;
	//lli ans=__gcd(v[0],v[1]);
	cout<<res*p<<endl;
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
	//int t;
	//cin>>t;
	//seive();
	// for(int i=1;i<=t;i++)
	// {
	// 	//cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	seive();
	solve();
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
