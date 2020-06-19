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
	lli n=s.length();
	vector<lli>pi(n);
	pi[0]=0;
	for(lli i=1;i<n;i++)
	{
		lli j=pi[i-1];
		while(j>0 && s[i]!=s[j])
		{
			j=pi[j-1];
		}
		if(s[i]==s[j])
			j++;
		pi[i]=j;
	}
	return pi;


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
	
	string str;
	cin>>str;
	lli n=str.length();
	vector<lli>pi=prefix_function(str);
	lli p=pi[n-1];
	// lli per=n-p;
	// if(n%per==0)
	// {
	// 	cout<<str.substr(0,per)<<endl;
	// 	return 0;
	// }
	// //string sub=str.substr(0,p);
	// ///string nstr;
	// for(lli i=0;i<n-1;i++)
	// {

	// 	//nstr+=str[i];

	// }
	// if(nstr.find(sub)!=-1)
	// 	cout<<sub<<endl;
	// else
	// 	cout<< "Just a legend"<<endl;
	if(p==0)
	{
		cout<< "Just a legend"<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if(pi[i]==p)
			{
				cout<<str.substr(0,p)<<endl;
				return 0;
			}
		}
		lli j=pi[p-1];
		if(j!=0)
			cout<<str.substr(0,j)<<endl;
		else
			cout<<"Just a legend"<<endl;
	}
}
