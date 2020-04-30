#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
#define M 100000009
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	// s1=" "+s1;
	int k,i,j;
	cin>>k;
	lli power[s1.size()];
	// unordered_map<char,lli>arr;
	// for(i=0;i<s1.size();i++)
	// {
	// 	if(s2)
	// }
	int n=s1.size();
	lli p=31;
	power[0]=1;
	for(i=1;i<s1.size();i++)
	{
		power[i]=(p*power[i-1]);
	}
	vector<lli>hash(s1.size()+2,0);
	// hash[1]=s1[1]-'a'+1;
	for(i=0;i<s1.size();i++)
		hash[i+1]=(hash[i]+(s1[i]-'a'+1)*power[i])%M;
	unordered_map<lli,lli>mp;
	int c=0;
	for(i=1;i<=s1.size()-1;i++)
	{
		c=0;
		for(j=i;j<=s1.size()-1 ;j++)
		{
			if(s2[s1[j]-'a']=='0')

				c++;
			cout<<c<<endl;
			
			if(c<=k)
			{
				lli curr=(hash[j]-hash[i-1]);
				curr=(curr*power[s1.size()-i+1]);	
				mp[curr]++;
				cout<<"start "<<i<<" "<<"End "<<j;
				cout<<endl;
				cout<<curr<<" "<<mp.size()<<endl;
			}
		}
	}
	cout<<mp.size();



}