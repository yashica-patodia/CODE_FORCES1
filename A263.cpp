#include<bits/stdc++.h>
using namespace std;
int main()
{
int *a[5];
int in,jn;
int i,j;
for(i=0;i<5;i++)
a[i]=(int *)malloc(5*sizeof(int));
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
cin>>a[i][j];
}
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(a[i][j]==1)
{
in=i;
jn=j;
break;
}
}
}
int x=abs(2-in);
int y=abs(2-jn);
cout<<x+y;
}
