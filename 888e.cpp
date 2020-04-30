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
#define all(v) (v).begin(), (v).end()
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

typedef vector<plli> vplli;
long long MOD=1000000009;
vector <lli> get_subset(vector<int> &a1);

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x);
		x=(x*x);
	}
	return res;
}
int n,m;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	cin>>n>>m;
	int a[n+1];
	fr2(i,n)
	{
		cin>>a[i];
	}
	vector<int> a1,a2;
	fr2(i,n)
	{
		if(i%2==0)
			a1.eb(a[i]);
		else
			a2.eb(a[i]);
	}
	
	// fr2(i,sz(a1))
	// {
	// 	cout<<a1[i]<<" ";

	// }
	// cout<<endl;
	// fr2(i,sz(a2))
	// {
	// 	cout<<a2[i]<<" ";

	// }
	vector<lli> sub1,sub2;
	sub1=get_subset(a1);
	sub2=get_subset(a2);

	// fr2(i,sz(sub1))
	// {
	// 	cout<<sub1[i]<<" ";

	// }
	// cout<<endl;
	// fr2(i,sz(sub2))
	// {
	// 	cout<<sub2[i]<<" ";

	// }
	lli ans=INT_MIN;
	fr2(i,sz(sub1))
	{
		auto it=upper_bound(sub2.begin(),sub2.end(),m-1-sub1[i]);
		it--;
		ans=max(ans,sub1[i]+(*it));

	}
	cout<<ans<<endl;



}
vector <lli> get_subset(vector<int> &a1)
{
	int n=sz(a1);
	vector<lli>sub;
	fr2(i,1<<n)
	{
		lli sum=0;
		fr2(j,n)
		{
			if(i&(1<<j))
				sum=(sum+(a1[j]%m))%m;


		}
		//cout<<sum<<" ";
		sub.eb(sum);
	}
	sort(all(sub));
	return sub;
}
// A = {1,2} <M
// B = {2,3} <M

// A[i]+B[j] <2*M

// 0 1 2... M-1
// M ....  2M-1%M    -M

// B[i] < M-A[i]. >    --it

// M-A[i]+A[i] 

// lli ans=0;

// it = lower_bound(all(B),M-A[i]);
// if(it!=B.begin()){
// 	it--;
// 	ans=max(ans,(*it)+A[i])
// }
// ans=max(ans,(B.back()+A[i])%M)