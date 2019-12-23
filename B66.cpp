#include<bits/stdc++.h>
using namespace std;
int *a;
int rain(int ind,int n);
int main()
{
int n,i;
cin>>n;

a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
int max=0;
for(i=0;i<n;i++)
{
int k=rain(i,n)+1;
if(k>max)
max=k;
}
cout<<max;
}
int rain(int ind,int n)
{
int c=0;
int in=ind;
int l=ind-1;
int r=ind+1;
while(l>=0)
{
if(a[l]<=a[ind])
{
c+=1;
ind=l;
l--;

}
else
break;
}
ind=in;
while(r<n)
{
if(a[r]<=a[ind])
{
c+=1;
ind=r;
r++;
}
else
break;
}
return c;
}

