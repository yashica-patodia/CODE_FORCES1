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

typedef vector<plli> vplli;
long long MOD=1000000009;
int check(int mm,map<int,int>mp,int arr[],int n);

int main()
{
// 		#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// 	#endif
	IOS
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+1];
		map<int,int>mp;
		fr2(i,n)
		{
			//int p;
			cin>>arr[i];
			mp[arr[i]]++;
			
		}
		// fr2(i,n)
		// {
		// 	if(mp[arr[i]]>1 )
		// 	{
		// 		same[k++];
		// 	}
		// // }
		// int lb=0,ub=(n+1)/2;
		// int mm,ans=ub;
		// while(lb<=ub)
		// {
		// 	mm=lb+(ub-lb)/2;
		// 	if(check(mm,mp,arr,n))
		// 	{
		// 		ans=mm;
		// 		lb=mm-1;
		// 	}
		// 	else
		// 		ub=mm+1;
		// }
		

	//}
//}
//int check(int mm,map<int,int>mp,int arr[],int n)
//{
	int cnt=0,cmax=0;
	fr2(i,n)
	{
		if(mp[arr[i]]>1)
			cnt=mp[arr[i]];
		cmax=max(cnt,cmax);

	}
	//cout<<cmax<<" "<<(int)mp.size()<<endl;
	if(cmax==0 && n!=1)
	{
		cout<<1<<endl;
		continue;
	}
	if(n==0)
	{
		cout<<0<<endl;
		continue;
	}
	if(cmax-1==(int)mp.size())
	{
		cout<<cmax-1<<endl;
		continue;
	}
	 else 
	cout<<min(cmax,(int)mp.size()-1)<<endl;
	 

}
}
	
	
	

//}