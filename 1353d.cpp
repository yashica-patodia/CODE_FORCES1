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
void solve()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<1<<endl;
		return;
	}
	int arr[n+1]={0};
	int cnt=0;
	if(n%2==1)
	{
	//int len=n;
	//int arr[n+1]={0};
	int l=1,r=n;
	//int cnt=0;
	while(l<r)
	{
		cnt++;
		if((r-l+1)%2==1)
		{
		
			arr[(l+r)/2]=cnt;
			r=(l+r)/2;
			--r;
		}
		else
		{
			arr[(l+r-1)/2]=cnt;
			r=(l+r-1)/2;
			--r;
		}




	}
	r=n;
	if(n%2==1)
	l=((l+r)/2)+1;
else
	l=((l+r-1))/2;
	//r=n;
	while(l<r)
	{
		cnt++;
		if((r-l+1)%2==1)
		{
			arr[(l+r)/2]=cnt;
			l=(l+r)/2;
			++l;
		}
		else
		{
			arr[(l+r-1)/2]=cnt;
			l=(l+r-1)/2;
			++l;
		}

	}
}
else
{
	//int len=n;
	
	int l=1,r=n;
	//int cnt=0;
	while(l<r)
	{
		cnt++;
		if((r-l+1)%2==1)
		{
			arr[(l+r)/2]=cnt;
			l=(l+r)/2;
			++l;
		}
		else
		{
			arr[(l+r-1)/2]=cnt;
			l=(l+r-1)/2;
			++l;
		}




	}
	l=1;
	if(n%2==1)
	r=((l+r)/2)-1;
else
	r=((l+r-1)/2)-1;
	//r=n;
	while(l<r)
	{
		cnt++;
		if((r-l+1)%2==1)
		{
			arr[(l+r)/2]=cnt;
			r=(l+r)/2;
			--r;
		}
		else
		{
			arr[(l+r-1)/2]=cnt;
			r=(l+r-1)/2;
			--r;
		}

	}

}
if(n%2==1)
{
lli cnt=1;
arr[n/2]=1;
int l=1,r=n;
int l2=1,r2=n;
for(int i=0;i<n;i++)
{
	cnt++;
	if(cnt%2==0)
	{
		arr[(l+r)/2]=cnt;
		l


	}

}
	for(int i=1;i<=n;i++)
	{
		if(arr[i]!=0)
			cout<<arr[i]<<" ";
		else
		{
			cnt++;
			cout<<cnt<<" ";
		}
	}
	cout<<endl;

}
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
