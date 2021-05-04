#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
int *a;
a=new int[n];
for(i=0;i<n;i++)
cin>>a[i];
int m;
cin>>m;
int pi;
int *pos;
pos=new int[n+1];
for(i=0;i<n;i++)
{
int k=a[i];
pos[k]=i;
}
long long int v=0,p=0;
int *b;
b=new int[m];
//for(i=0;i<m;i++)
//cin>>b[i];
for(i=0;i<m;i++)
{
cin>>pi;
//pi=b[i];
v+=pos[pi]+1;
p+=n-pos[pi];
}
cout<<v<<" "<<p;
}

