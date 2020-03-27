#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int  main()
{
	lli n,k,i;
	lli s=0,c=0;
	cin>>n>>k;
	string str;
	cin>>str;
	vector<int>vec(30,0);
	for(i=0;i<n;i++)
	{
		int ch=str[i]-'A';
		vec[ch]++;

	}
	sort(vec.begin(),vec.end(),greater<int>());
	// for(i=0;i<vec.size();i++)
	// 	cout<<vec[i]<<" ";
	i=0;
	while(k!=0)
	{
		c=vec[i];

		if(c>k)
		{
			s+=k*k;
			break;
		}
		else
		{
			s+=c*c;
		}

		k=k-c;
		i++;



	}
	cout<<s;

}