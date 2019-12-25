#include <bits/stdc++.h>
using namespace std;
int main()

{
int n,m;
int x,y;
int i;
cin>>n>>m;
multimap<int,int,greater<int>>arr;
for(i=0;i<m;i++)
{
cin>>x>>y;
arr.insert(make_pair(y,x));
}
multimap <int,int> :: iterator it;
it=arr.begin();
int s=0,temp=0;
while( temp!=n && it!=arr.end())
{
if((it->second)<=n)
{
temp+=it->second;
n=n-it->second;
s+=(it->first)*(it->second);
it++;
}
else
{
s+=(it->first)*n;
temp+=n;
n=0;
}
}
cout<<s;
}
