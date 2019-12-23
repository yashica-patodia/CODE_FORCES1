#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,h,i,w=0;
cin>>n>>h;
int *a;
a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<n;i++)
{
if(a[i]>h)
w+=2;
if(a[i]<=h)
w+=1;
}
cout<<w;
}
