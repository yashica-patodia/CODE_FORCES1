//a cell that initially contains 'G or 'B cannot be blocked and can be tavelled through
// if there is any cell where 'G is adjacent to 'B' then the answer is straight 'NO'
//
// otherwise we can make the neighbouring cellls of all the bad people walls and check if the good persons can reach the destination
//when u need to check if several sources will reach the destination just do a bfs from the destination in the process of bfs 
//check if the required source is visited or not
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
bool check(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	else
		return false;
}
void solve()
{
	cin>>n>>m;
	int g=0,b=0;
	char ch[n+1][m+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ch[i][j];
			//cout<<ch[i][j]<<" ";
			if(ch[i][j]=='B')
				b++;
			if(ch[i][j]=='G')
				g++;
		}
	}
	//cout<<g<<" "<<b<<endl;
	for(int i=0;i<4;i++)
	{
		int xx=n-1+dx[i];
		int yy=m-1+dy[i];
		//cout<<xx<<" "<<yy<<endl;
		if(check(xx,yy))
		{
			//cout<<ch[xx][yy]<<" "<<"yp";
			if(ch[xx][yy]=='B')
			{
				if(g>0)
				{
					cout<<"No"<<endl;
					return;
				}
				cout<<"Yes"<<endl;
				return;

			}
		}
	}
	queue<pair<int,int>>q;

	for(int i=0;i<n;i++ )
	{
		for(int j=0;j<m;j++)
		{
			if(ch[i][j]=='B')
			{
				for(int dir=0;dir<4;dir++)
				{
					int xx=i+dx[dir];
					int yy=j+dy[dir];
					if(check(xx,yy))
					{
						if(ch[xx][yy]=='G')
						{
							cout<<"No"<<endl;
							return;
						}
						if(ch[xx][yy]=='.')
						{
							ch[xx][yy]='#';
						}
					}
				}
			}
			// if(ch[i][j]=='G')
			// 	q.push({i,j});

		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{



	// 	}
	// }
	bool vis[n][m];
	mset(vis,false);
	q.push({n-1,m-1});
	vis[n-1][m-1]=true;
	while(!q.empty())
	{
		int x=q.front().ff;
		int y=q.front().ss;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(check(xx,yy) && ch[xx][yy]!='#' && !vis[xx][yy])
			{
				vis[xx][yy]=1;
				q.push({xx,yy});
			}
		}


	}
	//int f=1;
	//if the matrix is true which means there is a path from that point to the destination and that should be true only for good people
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ch[i][j]=='G')
			{
				if(!vis[i][j])
				{
					cout<<"No"<<endl;
					return;
					// f=0;
					// break;
				}
			}
			if(ch[i][j]=='B')
			{
				if(vis[i][j])
				{
					cout<<"No"<<endl;
					return;
					// f=0;
					// break;
				}
			}

		}
	}
	cout<<"Yes"<<endl;


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
