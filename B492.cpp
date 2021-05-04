#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,l,i;
cin>>n>>l;
int *a;
a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
int sub=0;
double max=0.0;
for(i=0;i<n-1;i++)
{
sub=a[i+1]-a[i];
if(sub>max)
max=sub;
}
max=max/2.0;
int k=a[0]-0;
int k2=l-a[n-1];
double ans=(max>k)? (max>k2)? max:k2 :(k>k2)? k:k2;
cout<<fixed<<setprecision(10)<<ans;
}

