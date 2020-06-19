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
struct dsu
{
	vector<lli>par,s;
	lli n;
	lli conn;

	dsu(){}

	dsu(int _n)
	{
		n=_n;
		conn=_n;
		par.assign(n,0);
		s.assign(n,0);
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			s[i]=1;
		}
	}
	lli find(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}
	void merge(lli x,lli y)
	{
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			conn--;
			if(s[x]>=s[y])
			{
				s[x]+=s[y];
				par[y]=x;
			}
			else
			{
				s[y]+=s[x];
				par[x]=y;
			}

		}
	}
	lli comp()
	{
		return conn;
	}


};
void solve()
{
	lli n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	//lli ans=0;
	dsu uf(n);
		for(lli i=0;i<k;i++)
		{
			for(lli p=i+k;p<n;p+=k)
			{
				if(uf.find(i)!=uf.find(p))
				{
					uf.merge(i,p);
				}

			}
		}
		for(int i=0;i<n/2;i++)
		{
			if(n%2==1 && (i==(n-1)/2))
				continue;
			if(uf.find(i)!=uf.find(n-1-i))
			uf.merge(i,n-1-i);
		}
	//	lli p=uf.comp();
		// lli fre[n][26];
		// mset(fre,0);
		// //map<lli,lli>mp;
		// for(int i=0;i<n;i++)
		// {
		// 	fre[uf.find(i)][str[i]-'a']++;

		// }
		// for(lli i=0;i<n;i++ )
		// {
		// 	lli mx=INT_MIN;
		// 	for(lli j=0;j<26;j++)
		// 	{
		// 		if(fre[i][j]!=0)
		// 		{
		// 			mx=max(mx,fre[i][j]);
		// 		}

		// 	}
		// 	if(mx!=INT_MIN)
		// 	ans+=(uf.s[i]-mx);
		// }
		// cout<<ans<<endl;
		//other method of finding every member of the all the components of a dsu

		set<lli>st;
		for(int i=0;i<n;i++)
			st.insert(uf.find(i));
		map<lli,lli>mp;
		lli cnt=0;
		for(auto i:st)
			mp[i]=cnt++;
		lli fre[st.size()][26];
		mset(fre,0);
		// for(lli i=0;i<st.size();i++)
		// {
		// 	for(lli j=0;j<26;j++)
		// }
		for(int i=0;i<n;i++)
		{
			fre[mp[uf.find(i)]][str[i]-'a']++;
		}
		lli ans=0;
		for(int i=0;i<st.size();i++)
		{
			lli mx=INT_MIN;
			lli c=0;
			for(int j=0;j<26;j++)
			{
				mx=max(mx,fre[i][j]);
				c+=fre[i][j];
			}
			ans+=(c-mx);
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
