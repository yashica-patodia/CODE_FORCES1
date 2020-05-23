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
	int n,k;
	cin>>n>>k;
	vector<int>vec(k);
	stack<int>st;
	int f=0;
	int j=1;
	vector<int>res;
	for(int i=0;i<k;i++)
	{
		cin>>vec[i];
		res.eb(vec[i]);
		while(!st.empty())
		{
			if(st.top()==j)
			{
				j++;
				st.pop();
			}
			else
				break;
		}
		if(vec[i]==j)
		{
			j++;
			continue;
		}
		
		 if( !st.empty() && st.top()<vec[i])
		{
			f=1;
			break;
		}
		st.push(vec[i]);

	}
	if(f==1)
	{
		cout<<-1<<endl;
		//continue;
	}
	else
	{
		while(!st.empty())
		{
			if(st.top()==j)
			{
				j++;
				st.pop();
			}
			else
				break;
		}
		while(j<=n)
		{
			if(st.empty())
				st.push(n+1);
			int p=st.top()-1;
			while(p>=j)
			{
				res.eb(p);
				p--;
			}
			j=st.top()+1;
			st.pop();
		}
		for(auto i:res)
			cout<<i<<" ";
	}
}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	clock_t start,end;
	start=clock();
	int t;
	//factorial();
	//cin>>t;
	t=1;
	for(int i=1;i<=t;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();

	}
}
	
