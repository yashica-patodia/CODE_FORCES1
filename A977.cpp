#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
int c=1,d;
while(c<=k)
{
d=n%10;
if(d==0)
n=n/10;
else
n=n-1;
c++;
}
cout<<n;
}
