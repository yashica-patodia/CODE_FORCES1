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
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	int wt[28];
	fr2(i,26)
	cin>>wt[i];
	string str;
	cin>>str;
	int pre[sz(str)+1];
	pre[0]=wt[str[0]-'a'];
	inc2(i,1,sz(str)-1)
	pre[i]=pre[i-1]+wt[str[i]-'a'];
	int  cnt=0;
	fr2(i,sz(str))
	{
		char temp[sz(str)+1];
		int index=0;
		inc2(j,i+1,sz(str))
		{
			//temp[index++]=str[j];
			//cout<<str.substr(i,j-i+1)<<endl;
			//temp[index]='\0';
			//if((j-i+1)%2==0)
			//{
				if((pre[j-1]-pre[i])==0 && str[j]==str[i])
					cnt++;


			//}
		}

	}
	cout<<cnt<<endl;

	
}
