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
lli n;
vector<lli>s;
const lli N=1e5+10;
struct node
{
	lli yg,cnt;
	node(lli yg1=-1,lli cnt1=0)
	{
		yg=yg1;
		cnt=cnt1;
	}
};
node t[4*N+10];
node merge(node a,node b)
{
	if(a.yg==-1)
		return b;
	if(b.yg==-1)
		return a;
	node res;
	lli yp=__gcd(a.yg,b.yg);
	if(a.yg==b.yg )
	{
		res={a.yg,a.cnt+b.cnt};
	}
	else if(yp==a.yg)
	{
		res={a.yg,a.cnt};
	}
	else if(yp==b.yg)
	{
		res={b.yg,b.cnt};
	}
	else
	{
		res={yp,0};
	}
	return res;
}
void build(lli ind,lli l,lli r)
{
	if(l==r)
	{
		t[ind]={s[l],1};
		return;
	}
	lli mm=(l+r)/2;
	build(2*ind,l,mm);
	build(2*ind+1,mm+1,r);
	t[ind]=merge(t[2*ind],t[2*ind+1]);
}
node query(lli ind,lli l,lli r,lli lq,lli rq)
{
	if(l>rq || r<lq)
	{
		node res;
		res={-1,0};
		return res;
	}
	lli mm=(l+r)/2;
	if(lq<=l && rq>=r)
		return t[ind];
	return merge(query(2*ind,l,mm,lq,rq),query(2*ind+1,mm+1,r,lq,rq));
}
void solve()
{
	cin>>n;
	s.resize(n);
	for(lli i=0;i<n;i++)
		cin>>s[i];
	
	build(1,0,n-1);
	// for(lli i=1;i<=9;i++)
	// {
	// 	node res=t[i];
	// 	cout<<res.yg<<" "<<res.cnt<<endl;

	// }
	
	lli t;
	cin>>t;
	while(t--)
	{
		lli l,r;
		cin>>l>>r;
		l--;
		r--;
		//cout<<l<<" "<<r<<"yp2"<<endl;
		node res=query(1,0,n-1,l,r);
		//cout<<res.cnt<<" "<<"yp"<<endl;
		cout<<r-l+1-res.cnt<<endl;

	}

}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
// 	clock_t start,end;
// 	start=clock();
// 	int t;
// 	cin>>t;
// 	for(int i=1;i<=t;i++)
// 	{
// 		cout<<"Case #"<<i<<": ";
// 		solve();

// 	}
	
	
// 	end=clock();
	
// 	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
// 	cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	solve();
}
