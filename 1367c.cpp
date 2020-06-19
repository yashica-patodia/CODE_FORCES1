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
vector<lli> prefix_function(string &s)
{
	lli n=s.size();
	vector<lli>pi(n);
	for(lli i=1;i<n;i++)
	{
		lli j=pi[i-1];
		while(j>0 && s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;

	}
	return pi;
}
vector<lli> find_occurences(string &text,string &pattern)
{
	string cur=pattern+'#'+text;
	lli sz1=text.size(),sz2=pattern.size();
	vector<lli>v;
	vector<lli>pi=prefix_function(cur);
	for(lli i=sz2+1;i<=sz1+sz2;i++)
	{
		if(pi[i]==sz2)
			v.eb(i-2*sz2);
	}

	return v;
}
void solve()
{
	lli n,k;
	cin>>n>>k;
	string str;
	cin>>str;
// 	string ch="1";
// 	vector<lli>pp=find_occurences(str,ch);

	
// 	if(pp.size()==0)
// 	{
// 		cout<<(n+k)/(k+1)<<endl;
// 	// 		lli ans1=0,ans2=0;
// 	// for(int i=0;i<n;i+=k+1)
// 	// {
// 	// 	if(str[i]=='0')
// 	// 		ans1++;


// 	// }
// 	// for(int i=n-1;i>=0;i-=(k+1))
// 	// {
// 	// 	if(str[i]=='0')
// 	// 		ans2++;
// 	// }
// 	// cout<<max(ans1,ans2)<<endl;
// 	// 	return;

// 	}

// 	else
// 	{
// 		lli temp=pp[0];
// 		lli ans=0;
// 		ans+=((temp+k)/(k+1));
// 		// for(auto i:pp)
// 		// 	cout<<i<<" "<<endl;
// 		for(auto i=1;i<pp.size();i++)
// 		{
// 			if(pp[i]-pp[i-1]-3>=0)
// 			{
// 				lli len=pp[i]-pp[i-1]-3;
// 				ans+=(len+k)/(k+1);
// 			}
// 			if(n-pp[pp.size()]-2>=0)
// 			{
// 				lli l2=n-pp[pp.size()]-2;
// 				ans+=((l2+k)/(k+1));
// 			}
// 			//ans+=()


// 		}
// 		cout<<ans<<endl;
// }
// // for(int i=0;i<n;i++)
// // {
// // 	if(str[i]=='1')
// // 		continue;
// // 	for(int j=i-1;j>=0;j--)
// // 	{
// // 		if(str[j]=='1')
// // 			continue;
// 		if(abs(j-i))



// 	}
// }
// 		set<int>st;
// 		int c=0;
// 		for(auto i:pp)
// 	{
// 		st.insert(i);
// 	}
	
// 		lli temp=pp[0];
// 		for(int i=0;i<n;i++)
// 		{
// 			auto it=st.begin();
// 			if(str[i]=='0' && abs(i-*it)==k+1)
// 			{
// 				c++;
// 				st.insert(i);
// 				st.erase(it);
// //	ind++;
// 			}
// 		}
// 		cout<<c<<endl;
// 	}
// // 	lli ans1=0,ans2=0;
// // 	for(int i=0;i<n;i+=k+1)
// // 	{
// // 		if(str[i]=='0')
// 			ans1++;


// 	}
// 	for(int i=n-1;i>=0;i-=(k+1))
// 	{
// 		if(str[i]=='0')
// 			ans2++;
// 	}
// 	cout<<max(ans1,ans2)<<endl;
	if(n==1)
	{
		if(str[0]=='1')
			cout<<0<<endl;
		else 
			cout<<1<<endl;
		return;
	}
	lli pre[n+1]={0};
	pre[0]=0;
	lli ans=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(str[i-1]-'0');

	}
	for(int i=1;i<=n;i++)
	{
		if(str[i-1]=='1')
			continue;

		if(i+k<=n && i-k-1>=0)
		{
			if(pre[i+k]==pre[i] && pre[i-k-1]==pre[i])
			{
				ans++;
				i=i+k;
			}
		}
		else if (i-k>=1)
		{
			if(pre[i-k-1]==pre[i] && pre[n]==pre[i])
			{
				ans++;
				i+=k;
			}
		}
		else if(i+k<=n)
		{
			if(pre[0]==pre[i] && pre[i+k]==pre[i])
			{
				ans++;
				i+=k;
			}

		}
		else
		{
			if(pre[0]==pre[i] && pre[i]==pre[n])
			{
				ans++;
				i+=k;
			}
		}
	}
	cout<<ans<<endl;
// }}
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
