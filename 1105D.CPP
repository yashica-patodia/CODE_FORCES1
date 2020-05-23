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
int n,m,p;
vector<lli>s;
char grp[1010][1010];
const int N=1010;
//vector<string>grp;
//vector<vector<char> >grp;
vector<int>dis;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//bool vis[N][N];
queue<pair<int,int>>q[10];
//vector<vector<int> >d;
//map<int,vector<int> >d;
//vector<pair<int,int> >pos;
int d[1010][1010];
bool check(int x,int y)
{
	if((x>=1 && x<=n)&& (y>=1 && y<=m) )
	{
		if(d[x][y]==-1)
		return true;
	else
		return false;
	}
	else
		return false;
}
void solve()
{
	cin>>n>>m>>p;
	s.resize(p+1);
	//pos.resize(p+1);
	//grp.resize(n+1);
	//d.resize(n+1);
	dis.resize(p+1);
	for(int i=1;i<=p;i++)
		cin>>s[i];
	//cout<<s[1]<<" ";
	for(int i=1;i<=n;i++)
	{
		//string str;
		//cin>>grp[i];
		for(int j=1;j<=m;j++)
		{
		cin>>grp[i][j];

		//cout<<grp[i][j]<<" ";
		if(isdigit(grp[i][j]))
		{
			int dd=(int)grp[i][j]-48;
			//cout<<dd<<" ";
			//pos.eb({i,j});
			//q.push({{i,j},d});
			q[dd].push({i,j});
			dis[dd]+=1;
			//cout<<dis[d]<<" ";
			//d[i].eb(0);
			d[i][j]=0;



		}

		else if(grp[i][j]=='.')
			//d[i].eb(-1);
			d[i][j]=-1;
		else if(grp[i][j]=='#')
			//d[i].eb(1);
			d[i][j]=1;

	}}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 		cout<<d[i][j]<<" ";
	// 	cout<<endl;
	// }
	//cout<<d[1][1]<<" ";
	int f=0;
	int turn=0;
	while(1)
	{
		turn++;
		f=0;
		for(int i=1;i<=p;i++)
		{
			while(!q[i].empty())
			{
				int x=q[i].front().ff;
				int y=q[i].front().ss;
			//	cout<<x<<" "<<y<<endl;
				
				if(d[x][y]>=(turn*s[i]))
					break;
				q[i].pop();
				for(int j=0;j<4;j++)
				{
					int xx=x+dx[j];
					int yy=y+dy[j];
				
					if(check(xx,yy))
					{
					//	cout<<i<<" "<<xx<<" "<<yy<<endl;
						d[xx][yy]=d[x][y]+1;
						q[i].push({xx,yy});
						dis[i]+=1;
					}

				}
			}
			if(!q[i].empty())
				f=1;
		}
		if(f==0)
			break;

	}
for(int i=1;i<=p;i++)
	cout<<dis[i]<<" ";
cout<<endl;

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

	solve();
}
