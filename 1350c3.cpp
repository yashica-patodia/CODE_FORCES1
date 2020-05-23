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
lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}

void solve()
{
	int n;
	cin>>n;
	lli arr[n];
	fr2(i,n)
	cin>>arr[i];
	if(n==2)
	{
		cout<<(arr[0]*arr[1])/__gcd(arr[0],arr[1])<<endl;
		return;
	}
	map<lli,vector<lli> >mp;
	for(int i=0;i<n;i++)
	{
		lli temp=arr[i];
		while(temp>1)
		{
			lli cnt=0;
			lli curr=lpf[temp];
			//mp[lpf[temp]]
			while(temp%curr==0)
			{
				cnt++;
				temp/=curr;
			}
			mp[curr].eb(cnt);
		}
	}
	lli ans=1;
	for(auto j=mp.begin();j!=mp.end();j++)
	{
		//out<<j->ff<<" ";
		//cout<<sz(j->ss)<<" ";
		lli s1=1e15,s2=1e15;
		for(auto k:j->ss)
		{
			//cout<<k<<" ";
			if(sz(j->ss)==1)
			{
				s2=s1=0;
				//ans=(ans*(pwr(j->ff,k)));
				break;
			}
			else if(sz(j->ss)==n || sz(j->ss)==n-1)
			{

				if(k<s1)
				{
					s2=s1;
					s1=k;
				}
				else if(k<s2 )
					s2=k;

				

			}
			else
			{
				s2=s1=0;
				break;
			}
			

			//cout<<k<<" ";
		}
		if(s2==1e15)
			s2=s1;
		if(sz(j->ss)==n)
		//cout<<endl;
		//cout<<j->ff<<" "<<s2<<endl;
		ans=(ans*pwr(j->ff,s2));
	else
		ans=(ans*pwr(j->ff,s1));
		
	}
	cout<<ans<<endl;

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
