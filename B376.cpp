#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m,a,b,c,s=0,i;
cin>>n>>m;
int arr[n];
for(i=0;i<n;i++)
arr[i]=0;
for(i=1;i<=m;i++)
{
cin>>a>>b>>c;
arr[a-1]-=c;
arr[b-1]+=c;
}
for(i=0;i<n;i++)
{
if(arr[i]>0)
s+=arr[i];
}
cout<<s;
}
