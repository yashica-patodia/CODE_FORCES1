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
long long MOD=1000000007;
double startTime;
double getCurrentTime()
{
	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli inver(lli num)
{
	return pwr(num,MOD-2);
}
lli findncr(lli n,lli r)
{
	r=min(r,n-r);
	if(n==0||n==1||r==0)
		return 1;
	lli numer=1;
	for(lli i=n;i>=n-r+1;i--)
		numer=(numer*i)%MOD;
	lli den=1;
	for(lli i=2;i<=r;i++)
		den=(den*i)%MOD;
	den=inver(den);
	lli res=(numer*den)%MOD;
	return res;
}
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

lli add(lli a,lli b)
{
	lli res=a+b;
	if(res>=MOD)
		return res-MOD;
	return res;

}
lli  mult(lli a,lli b)
{
	lli res=a;
	res=(res*b)%MOD;
	return res;

}
const int n=4;
struct matrix
{
	int arr[n][n];
	void reset()
	{
		memset(arr,0,sizeof(arr));
	}
	void makeiden()
	{
		reset();
		for(int i=0;i<n;i++)
			arr[i][i]=1;
	}
	matrix operator +(const matrix &o) const
	{
		matrix res;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				res.arr[i][j]=add(arr[i][j],o.arr[i][j]);
		}
		return res;
	}
	matrix operator *(const matrix &o) const
	{
		matrix res;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				res.arr[i][j]=0;
				for(int k=0;k<n;k++)
				{
					res.arr[i][j]=add(res.arr[i][j],mult(arr[i][k],o.arr[k][j]));
				}
			}
		}
		return res;
	}

};
matrix power(matrix a,int b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	lli n;
	cin>>n;
	matrix M;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==j)
				M.arr[i][j]=0;
			else
				M.arr[i][j]=1;
		}
	}
	matrix expo=power(M,n);
	// for(int i=0;i<4;i++)
	// {
	// 	for(int j=0;j<4;j++)
	// 		cout<<M.arr[i][j]<<" ";
	// 	cout<<endl;
	// }
	// for(int i=0;i<4;i++)
	// {
	// 	for(int j=0;j<4;j++)
	// 		cout<<expo.arr[i][j]<<" ";
	// 	cout<<endl;
	// }
	lli ans=(expo.arr[0][0])%MOD;
	cout<<ans<<endl;
}