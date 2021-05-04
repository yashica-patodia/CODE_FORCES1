#include<bits/stdc++.h>
using namespace std;
int main()
{
int k,r,s,c;
cin>>k>>r;
s=k;
c=1;

for(; ;)
{
if(s%10==0 || s%10==r)
{

break;
}
else
{
s+=k;
c++;
}
}
cout<<c;
}
