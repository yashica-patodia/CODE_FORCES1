#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin, (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
long long MOD=1000000009;

typedef vector<plli> vplli;
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	int n;
	cin>>n;
	lli a[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int left[n+1];
	int right[n+1];
	stack<int>st1;
	fr2(i,n)
	{
		while(!st1.empty() && a[st1.top()]>=a[i])
			st1.pop();
		if(st1.empty())
			left[i]=-1;
		else
			left[i]=st1.top();
		st1.push(i);
	}
	while(!st1.empty())
		st1.pop();
	for( int i=n-1;i>=0;i--)
	{
		while(!st1.empty() && a[st1.top()]>=a[i])
			st1.pop();
		if(st1.empty())
			right[i]=n;
		else
			right[i]=st1.top();
		st1.push(i);


	}
	
	int cnt[n+1];
	fr(i,n)
		cnt[i]=right[i]-left[i]-1;
	// 	fr2(i,n)
	// cout<<left[i]<<" "<<right[i]<<" "<<cnt[i]<<endl;

	lli ans[n+1];
	mset(ans,0);
	for( int i=0;i<n;i++)
	{
		ans[cnt[i]]=max(a[i],ans[cnt[i]]);
		//cout<<ans[cnt[i]]<<" "<<a[i]<<endl;
	}
	// inc2(i,1,n)
	// cout<<ans[i]<<" ";	
	// cout<<endl;

	for(int i=n;i>=1;i--)
	{
		if(ans[i]!=0)
			continue;
		else
			ans[i]=ans[i+1];
	}
	// inc2(i,1,n)
	// cout<<ans[i]<<" ";	
	for(int i=n-1;i>=1;i--)
		ans[i]=max(ans[i],ans[i+1]);
	//cout<<endl;
	inc2(i,1,n)
	cout<<ans[i]<<" ";	





	
}
