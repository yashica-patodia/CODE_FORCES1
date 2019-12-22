#include<bits/stdc++.h>
using namespace std;
double dis(int x,int y,int x1,int y1);
int main()
{
int n,k,x,y,i;
double s=0.0;
cin>>n>>k;
vector<pair<int ,int>>vec;

for(i=0;i<n;i++)
{
cin>>x>>y;
vec.push_back(make_pair(x,y));
}
for(i=0;i<n-1;i++)
{
double d=dis(vec[i].first,vec[i].second,vec[i+1].first,vec[i+1].second);
s+=d;
}
s=s*k;
s=s/50.0;
cout<<fixed<<setprecision(9)<<s;
}
double dis(int x,int y,int x1,int y1)
{
double sq=sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
return sq;
}
