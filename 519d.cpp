#include<bits/stdc++.h>
using namespace std;
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

int main()

{
			#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	map<lli ,lli>mp;

	fr(i,26)
	{
		lli wt;
		cin>>wt;
		mp.ins(plli(i,wt));
	}
	// fr(i,26)
	// cout<<mp[i]<<" ";
	string str;
	cin>>str;
	vector<lli>dp((lli)str.length()+1,0);
	dp[0]=mp[str[0]-'a'];
	inc(i,1,str.length()-1)
	{
		dp[i]=dp[i-1]+mp[str[i]-'a'];

	}
	// fr(i,str.length())
	// cout<<dp[i]<<" ";
	lli cnt=0;
	fr(i,str.length())
	{
		for(lli l=2;l<=(lli)str.length()-i;l+=2)
		{
			lli j=l+i-1;
			string s1=str.substr(i,l);
			//cout<<s1<<endl;
			if(i!=0)
			{
			if(s1[0]==s1[(lli)s1.length()-1] && (dp[j]-dp[i-1]-(2*mp[s1[0]-'a']))==0)
				cnt++;
			}
			else
			{
				if(s1[0]==s1[(lli)s1.length()-1] && (dp[j]-(2*mp[s1[0]-'a']))==0)
					cnt++;
			}

		}

	}
	cout<<cnt;

}
