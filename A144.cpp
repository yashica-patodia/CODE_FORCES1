#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
int *a,index=0,index2=0,sum=0;
a=new int [n];
for(i=0;i<n;i++)
cin>>a[i];
int min=a[0],max=a[0];
for(i=0;i<n;i++)
{
if(a[i]<=min)
{
min=a[i];
index=i;
}
if(a[i]>max)
{
max=a[i];
index2=i;
}
}
if(index2>index)
sum=index2+n-2-index;
if(index2<index)
sum=index2+n-1-index;
if(index2==index)
sum=0;
cout<<sum;
}

