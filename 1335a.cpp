#include<bits/stdc++.h>
using namespace std;
typedef  unsigned long long int lli;
int main()
{
	lli t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;
		if(n%2==0)
			cout<<(n/2)-1<<endl;
		else
			cout<<(n-1)/2<<endl;
	}

}