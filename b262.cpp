#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,s=0,i,c=0,f,p;
cin>>n>>k;
int a[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<n;i++)
{
if(a[i]<=0)
c++;
}
cout<<c<<endl;

for(i=0;i<min(c,k);i++)
a[i]*=-1;
if(k>c)
{
k=k-c;
if(k%2!=0)
{
if(c<n)
 f=(a[c-1]<=a[c])? a[c-1] :a[c];
if(c==n)
f=a[c-1];
cout<<f;
f*=-1;
if(c<n)
{
if(a[c-1]<=a[c])
f=a[c-1];
else
f=a[c];
}

if(c==n)
a[c-1]=f;
cout<<f<<" ";
}
}


/*if(c<k)
{
while(k!=0)
{
if(oe%2==0)
for(i=0;i<c,k>0;i++)
{
a[i]*=-1;
k--;
}
else
for(i=c-1;i>=0,k>0;i--)
{
a[i]*=-1;
k--;
}
oe++;
}*/

for(i=0;i<n;i++)
s+=a[i];
cout<<s;
}

