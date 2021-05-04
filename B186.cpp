#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,t1,t2,k,a,b,i;
multimap<double,int,greater<double>> arr;
multimap<double,int>:: iterator it;
cin>>n>>t1>>t2>>k;
for(i=1;i<=n;i++)
{
cin>>a>>b;
double m1=(1-.01*k)*a*t1+b*t2;
double m2=(1-.01*k)*b*t1+a*t2;
double max2=(m1>m2)? m1:m2;
arr.insert(pair<double,int>(max2,i));
}

for(it=arr.begin();it!=arr.end();it++)
cout<<it->second<<" "<<fixed<<setprecision(2)<<it->first<<endl;
}

