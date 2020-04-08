#include<bits/stdc++.h>
using namespace std;
typedef  unsigned long long int lli;
#define M 1000000009
int main()
{
	string s;
	string s2;
	lli i,j,k;
	cin>>s>>s2>>k;
	lli p=31;
	lli n=s.length();
	vector<lli>power(n+1);
	power[0]=1;
	for(i=1;i<n;i++)
		power[i]=(power[i-1]*p)%M;
	vector<lli>h(n+1,0);
	for(i=0;i<n;i++)
		h[i+1]=(h[i]+(s[i]-'a'+1)*power[i])%M;
	vector<lli>cnt(n+1,0);

	
		if(s2[s[0]-'a']=='0')
			cnt[0]=1;
		for(i=1;i<n;i++)
		{
			if(s2[s[i]-'a']=='0')
				cnt[i]=1+cnt[i-1];
			else
				cnt[i]=cnt[i-1];
		}
		// for(i=0;i<n;i++)
		// 	cout<<cnt[i]<<endl;
	
	lli c=0,bad;
	for(i=1;i<=n;i++)
	{
		set<lli>hs;
		for(j=0;j<=n-i;j++)
		{
			if(j>=1)
				bad=cnt[j+i-1]-cnt[j-1];
			else
				bad=cnt[i-1+j];
				
			if(bad<=k)
			{
			lli curr=(h[i+j]-h[j]+M)%M;
			curr=(curr*power[n-j-1])%M;
			// cout<<curr<<" ";
			hs.insert(curr);
			}
		}
				c+=hs.size();
				// cout<<c<<endl;

	}
cout<<c;

}