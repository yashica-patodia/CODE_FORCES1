#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,f,x,y,i,z,p,min2;
cin>>n>>f;
multimap<int,int,greater<int>> a;
for(i=0;i<n;i++)
{
cin>>x>>y;
a.insert(pair<int,int>(y,x));
}
int s=0;
multimap<int,int>:: iterator it;
for(it=a.begin();it!=a.end();it++)
cout<<it->first<<" "<<it->second<<endl;
for(i=0;i<f;i++,it++)
{
 z=(it->second)*2;
 p=it->first;
 min2=(z<p)?z:p;
cout<<z<<" "<<p<<" "<<min2<<endl;
s+=min2;
}
for(i=f;i<n;i++,it++)
{
z=it->second;
 p=it->first;
 min2=(z<p)?z:p;
cout<<z<<" "<<p<<" "<<min2<<endl;
s+=min2;
}
cout<<s;

}
