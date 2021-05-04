#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,m,i,x,y;
vector<int,int,greater<int> >vec;
cin>>n>>m;
for(i=0;i<m;i++)
{
cin>>x>>y;
vec.push_back(make_pair(y,x));
//cin>>vec[i].second>>vec[i].first;
}

//sort(vec.begin(),vec.end());
for(i=0;i<m;i++)
cout<<vec[i].second<<" ";
i=0;
int s=0;
while(n!=0)
{
n=n-(vec[i].second);
s+=(vec[i].first)*(vec[i].second);
i++;
}
cout<<s;
}

