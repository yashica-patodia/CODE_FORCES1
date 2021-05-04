#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int *a;
a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
int min2=a[0];
for(i=1;i<n;i++)
{
if(a[i]<=min)
{
min=a[i];
ind=i;
}
}
for(
