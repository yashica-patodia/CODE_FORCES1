#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,c,d=0,i,j;
cin>>n;
int *a[n];
for(i=0;i<n;i++)
a[i]=(int *)malloc(3*sizeof(int));

for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
cin>>a[i][j];

}
for(i=0;i<n;i++)
{
c=0;
for(j=0;j<3;j++)
{
if(a[i][j]==1)
c+=1;
}
if(c>=2)
d+=1;
}
cout<<d;
}
