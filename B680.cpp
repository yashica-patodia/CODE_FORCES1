#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,n,i,c=0;
cin>>n>>a;
int *b;
b=new int[n];
for(i=0;i<n;i++)
cin>>b[i];
a=a-1;
int *d;
d=new int[n-a];
for(i=0;i<n-a;i++)
d[i]=0;
if(b[a]==1)
d[0]=1;
int a2=(a<=n-1-a)? a: n-1-a;
for(i=1;i<=a2;i++)
{
if(b[a-i]==1)
d[i]+=1;
if(b[a+i]==1)
d[i]+=1;
}
if(d[0]==1)
c+=1;
for(i=1;i<=a2;i++)
{
if(d[i]==2)
c+=2;
}
if(a<(n-1-a))
{
for(i=2*a+1;i<n;i++)
{
if(b[i]==1)
c+=1;
}
}
if(a>(n-1-a))
{
for(i=0;i<=2*a-n;i++)
{
if(b[i]==1)
c+=1;
}
}
cout<<c;
}
