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
void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int>>vp;

	vp.resize(n);
	vector<pair<int,int>>arr;
	arr.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>vp[i].ff;
		arr[i].ff=vp[i].ff;
		arr[i].ss=i;

	}
	for(int i=0;i<n;i++)
		cin>>vp[i].ss;
	int f=1;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]<=arr[i+1])
			continue;
		else 
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		cout<<"Yes"<<endl;
		return;
	}
	else
	{
		sort(all(arr));
		// int temp,temp2;
		// for(int i=0;i<n-1;i++)
		// {
		// 	for(int j=0;j<n-i-1;j++)
		// 	{
		// 		if(vp[j].ff>vp[j+1].ff)
		// 		{
		// 			if(vp[j].ss!=vp[j+1].ss)
		// 			{
		// 			temp=vp[j].ff;
		// 			vp[j].ff=vp[j+1].ff;
		// 			vp[j+1].ff=temp;
		// 			temp2=vp[j].ss;
		// 			vp[j].ss=vp[j+1].ss;
		// 			vp[j+1].ss=temp2;



		// 			}
					
		// 				//swap(vp[j],vp[j+1]);
					
		// 		}
		// // 		for(auto i:vp)
		// // 	cout<<i.ff<<" ";
		// // cout<<endl;
		// 	}
		// }

		// for(auto i:vp)
		// 	cout<<i.ff<<" ";
		// for(auto i:arr)
		// 	cout<<i.ff<<" ";

		// for(int i=0;i<n;i++)
		// {
		// 	if(vp[i].ff!=arr[i].ff)
		// 	{
		// 		if(vp[])
		// 	}

		// }
		vector<vector<int>>adj;
		vector<int>vis(n+1,false);
		//vis.resize(n+1);
		adj.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(vp[i].ss!=vp[j].ss)
				{
					adj[i].eb(j);
					adj[j].eb(i);

				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				queue<int>q;
				vector<int>v1;
				vector<int>v2;
				vis[i]=true;
				q.push(i);
				while(!q.empty())
				{
					int u=q.front();
					v1.eb(arr[u].ff);
					v2.eb(vp[u].ff);
					q.pop();
					for(auto i:adj[u])
					{
						if(!vis[i])
						{
							vis[i]=true;
							q.push(i);
						}
					}
				}
				sort(all(v1));
				sort(all(v2));
				if(v1!=v2)
				{
					cout<<"No"<<endl;
					return;
				}
			}
		}
		cout<<"Yes"<<endl;
		// for(int i=0;i<n;i++)
		// {
		// 	if(arr[i].ff==vp[i].ff)
		// 		continue;
		// 	else
		// 	{
		// 		cout<<"No"<<endl;
		// 		return;
		// 	}
		// }
		// cout<<"Yes"<<endl;

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
