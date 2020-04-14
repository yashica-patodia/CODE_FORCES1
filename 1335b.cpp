#include<bits/stdc++.h>
using namespace std;
typedef  unsigned long long int lli;
int main()
{
	lli t;
	cin>>t;
	string str="abcdefghijklmnopqrstuvwxyz";
	while(t--)
	{
		lli n,a,b,i;
		cin>>n>>a>>b;
		//char ch[n+1];
		string ans;
		lli d=n/b;
		lli rem=n%b;
		for(i=0;i<d;i++)
			ans+=str.substr(0,b);
		ans+=str.substr(0,rem);
		cout<<ans<<endl;





		
	}
}