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
int n,m;
char mat[1010][1010];
bool check(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)
	{
		if(mat[x][y]=='#')
			return false;
		return true;
	}
	return false;

}
void solve()
{
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	}

	deque<pair<int,int>>dq;
	lli dis[4][n][m];
	mset(dis,-1);
	for(int k=1;k<=3;k++)
	{
		dq.clear();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mat[i][j]-'0'==k)
				{
					dis[k][i][j]=0;
					dq.push_back({i,j});
				}

			}
		}
		while(!dq.empty())
		{
			int x=dq.front().ff;
			int y=dq.front().ss;
			dq.pop_front();
			for(int d=0;d<4;d++)
			{
				int xx=x+dx[d];
				int yy=y+dy[d];
				if(check(xx,yy))
				{
					lli fd=dis[k][x][y]+(mat[xx][yy]=='.');
					if(dis[k][xx][yy]==-1 || dis[k][xx][yy]>fd )
					{
						dis[k][xx][yy]=fd;
						if(mat[xx][yy]=='.')
							dq.push_back({xx,yy});
						else
							dq.push_front({xx,yy});
					}
				}
			}

		}

	}
	lli ans=MOD;
	// for(int k=1;k<=3;k++)
	// {
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 		cout<<dis[k][i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	// }
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(dis[1][i][j]!=-1 && dis[2][i][j]!=-1 && dis[3][i][j]!=-1)
				ans=min(ans,dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-(2*(mat[i][j]=='.')));
			}
		}
		

	
	if(ans==MOD)
		cout<<-1<<endl;
	else
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
