#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	cin>>t,n;
	while(t--)
	{
		lli num;
		vector<lli>vec1;
		vector<lli>vec2;
		cin>>n;
		int  f=1;
		for(i=0;i<n;i++)
		{
			cin>>num;

			if(num<0)
			{
				f=0;
				vec2.push(num);
			}
			else
				vec1.push(num);



		}
		if(vec2.empty())
		{
			
		}
	}
}