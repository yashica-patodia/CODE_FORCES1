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
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		lli one=0;
		lli zer=0;
		fr(i,sz(str))
		{
			if(str[i]=='1')
				one++;
			else
				zer++;
		}
		if(one==0 && zer==sz(str))
		{
			cout<<str<<endl;
			continue;
		}
	else	if(zer==0 && one==sz(str))
	{
			cout<<str<<endl;
			continue;
	}
		else 
		{
		//lli mine=max(one,zer);
		if(str[0]=='1')
		{
			fr(i,sz(str))
		
		{
			cout<<"10";
		}

		cout<<endl;
		continue;
		}
		if(str[0]=='0')
		{
			fr(i,sz(str))
			{
				cout<<"01";
			}
			cout<<endl;
		}
	}
}
}		




	