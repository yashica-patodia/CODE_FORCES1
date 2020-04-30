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
bool issafe(lli crow,lli ccol,lli prow,lli pcol);
void ways(lli rows,vector<lli> &prev);
void display(vector<lli> &prev);

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
int n;
lli ans=0;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	vector<lli>prev={};
		n=12;
	ways(0,prev);
	cout<<ans;
	// if(ans==0)
	// 	cout<<"Not possible"<<endl;


}
void ways(lli rows,vector<lli> &prev)
{
	if(rows==n)
	{
		ans++;
		//display(prev);
		return;

	}
	// if(ans>=1)
	// 	return ;
	fr(i,n)
	{
		bool	canplace=1;
		fr(j,sz(prev))
		{
			if(!issafe(rows,i,j,prev[j]))
			{
				canplace=0;
			}
		}
			if(canplace)
			{
				prev.eb(i);
				ways(rows+1,prev);
				prev.pop_back();
			}
		}
	}

bool issafe(lli crow,lli ccol,lli prow,lli pcol)
{
	if(ccol==pcol)
		return false;
	if(abs(ccol-pcol)==abs(crow-prow))
		return false;
	if(abs(prow-crow)==2 && abs(pcol-ccol)==1)
		return false;
	if(abs(prow-crow)==1 && abs(pcol-ccol)==2)
		return false;
	return true;
}
// void display(vector<lli> &prev)
// {
// 	if(ans==0)
// 	{
// 		cout<<"Not possible"<<endl;
// 		return;
// 	}
	
// 	lli chess[n+1][n+1];
// 	fr(i,n)
// 	{
// 		fr(j,n)
// 		{
// 			if(prev[i]==j)
// 			chess[i][j]=1;
// 			else
// 				chess[i][j]=0;


// 		}
// 	}
// 	fr(i,n)
// 	{
// 		fr(j,n)
// 		{
// 			cout<<chess[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}



// }