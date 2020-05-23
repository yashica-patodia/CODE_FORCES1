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
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,m,k;
char ch[501][501];
bool vis[501][501];
bool check(int x,int y)
{
	if((x>=0 && x<n) &&(y>=0 && y<m))
	{
		if(ch[x][y]=='.')
			return true;
		else
			return false;
	}
	else
		return false;
}
void solve()
{
	queue<pair<int,int> >q;
	//set<pair<int,int>>st;
	stack<pair<int,int>>st;

	int cnt=1;	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	
	{
		for(int j=0;j<m;j++)
		{
			vis[i][j]=false;
			
			cin>>ch[i][j];
			if(ch[i][j]=='.' && cnt==1)

			{
				cnt++;
				q.push({i,j});
				st.push({i,j});
				vis[i][j]=true;



			}

		}
		
		
	}
	int f=0;
	while(!q.empty())
	{
		//f++;
		int x=q.front().ff;
		int y=q.front().ss;
		q.pop();
		
		//ch[x][y]='X';
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(check(xx,yy) && !vis[xx][yy])
			{
				q.push({xx,yy});
				vis[xx][yy]=true;
				st.push({xx,yy});

			}
		}



	}
	//auto i=st.end();

	while(f<k)
	{
		//--i;

		int x=st.top().ff;
		int y=st.top().ss;
		ch[x][y]='X';
		st.pop();
		
		f++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<ch[i][j];
		cout<<endl;
	}

	

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
	// 	//cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	solve();

	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
