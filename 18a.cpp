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
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int dis(pair<int,int>p1,pair<int,int>p2)
{
	int x, y, x2, y2;
	x=p1.ff;
	y=p1.ss;
	x2=p2.ff;
	y2=p2.ss;
	return ((x-x2)*(x-x2)+(y-y2)*(y-y2));
}
bool check(int x1,int y1,int x2,int y2,int x3,int y3 )
{
	pii a={x1,y1};
	pii b={x2,y2};
	pii c={x3,y3};
	if((dis(a,b)==dis(a,c)+dis(b,c))|| (dis(a,c)==dis(b,c)+dis(b,a)) || (dis(b,c)==dis(a,b)+dis(a,c)))
		return true;
	else
	 return false;
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
	
	vector<pair<int,int>>v;
	fr2(i,3)
	{
		int x,y;
		cin>>x>>y;
	v.pb({x,y});
}
if((dis(v[0],v[1])==dis(v[1],v[2])+dis(v[2],v[0]))|| (dis(v[0],v[2])==dis(v[1],v[0])+dis(v[1],v[2])) || (dis(v[2],v[1])==dis(v[1],v[0])+dis(v[0],v[2])))
	cout<<"RIGHT";
else 
{
	int f=0;
	//for(int i=0;i<3;i++)
	//{i
	if(f==0)
	{
		for(int j=0;j<4;j++)
		{
			int xx=v[0].ff+dx[j];
			int yy=v[0].ss+dy[j];
			if(xx==v[1].ff && yy==v[1].ss)
				continue;
			if(xx==v[2].ff && yy==v[2].ss)
				continue;
			
			if(check(xx,yy,v[1].ff,v[1].ss,v[2].ff,v[2].ss))
			{
				f=1;
			
			break;
		}
		}
	}
	else if (f==0)
	{
		for(int j=0;j<4;j++)
		{
			int xx=v[1].ff+dx[j];
			int yy=v[1].ss+dy[j];
			if(xx==v[2].ff && yy==v[2].ss)
				continue;
			if(xx==v[0].ff && yy==v[0].ss)
				continue;
			if(check(xx,yy,v[0].ff,v[0].ss,v[2].ff,v[2].ss))
			{
				f=1;
				break;
			}
		}
	}
	else if(f==0)
	{
		for(int j=0;j<4;j++)
		{
			int xx=v[2].ff+dx[j];
			int yy=v[2].ss+dy[j];
			if(xx==v[1].ff && yy==v[1].ss)
				continue;
			if(xx==v[0].ff && yy==v[0].ss)
				continue;
			if(check(xx,yy,v[1].ff,v[1].ss,v[0].ff,v[0].ss))
			{
				f=1;
				break;
			}
		}
	}
		if(f==1)
			cout<<"ALMOST";
		else
			cout<<"NEITHER";


	//}
}
}
