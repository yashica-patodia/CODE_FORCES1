#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,i,s=0;
cin>>n>>k;
int *a;
a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<k;i++)
s+=a[i];
int min2=s;
int m=0;
for(i=1;i<=n-k;i++)
{
if(s<=min2)
{
min2=s;
m=i-1;
}
s+=a[i+k-1]-a[i-1];
}
if(s<=min2)
{min2=s;
m=i-1;
}

cout<<m+1;
}
