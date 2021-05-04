#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
int n,i,temp;
lli c=0;
cin>>n;
lli count[111111];
map<lli,lli>lastpos,period;
map<int,bool>fail;
//lli lastpos[100001];
//lli period[100001];
//bool fail[100001];
for(i=0;i<n;i++)
{
	cin>>temp;
	if(count[temp]==0)
	{
		count[temp]+=1;
//cout<<count[temp]<<endl;
		lastpos[temp]=i;
		period[temp]=0;
		fail[temp]=false;
	}
	 else if(count[temp]==1)
	{
		count[temp]+=1;
		period[temp]=i-lastpos[temp];
		lastpos[temp]=i;
	}
	else if(count[temp]==2)
	{
//out<<i<<" "<<lastpos[temp]<<" "<<period[temp]<<endl;
		if(i-lastpos[temp]!=period[temp])
		{
			fail[temp]=true;
//out<<temp<<" "<<fail[temp]<<endl;
			continue;
		}
		else
		{
			count[temp]+=1;
			lastpos[temp]=i;
		}
	}
 else if(count[temp]>2)
	{
		count[temp]+=1;
		if(fail[temp]==true)
		continue;
		else if ((i-lastpos[temp])!=period[temp])
		{
			fail[temp]=true;
			continue;
		}
		lastpos[temp]=i;
	}
}


for(map<int,bool>::iterator it=fail.begin();it!=fail.end();it++)
{
if(it->second==false)
c++;
}
cout<<c<<endl;
if(c!=0)
{
	map<lli,lli>::iterator itr;
	for(itr=period.begin();itr!=period.end();itr++)
	{
		if(fail[itr->first]==false)
		cout<<itr->first<<" "<<itr->second<<endl;
	}
}

}



