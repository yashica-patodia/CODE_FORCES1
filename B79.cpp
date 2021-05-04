#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m,k,t,x,y,i,j,c=0;
cin>>n>>m>>k>>t;
int **a=new int* [n];
for(i=0;i<n;i++)
a[i]=new int [m];


for(i=0;i<k;i++)
{
cin>>x>>y;
a[x-1][y-1]=3;
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(a[i][j]!=3)
{
if(c%3==0)
a[i][j]=0;
if(c%3==1)
a[i][j]=1;
if(c%3==2)
a[i][j]=2;
c++;
}
}
}
for(i=0;i<t;i++)
{
cin>>x>>y;
if(a[x-1][y-1]==0)
cout<<"Carrots"<<endl;
if(a[x-1][y-1]==1)
cout<<"Kiwis"<<endl;
if(a[x-1][y-1]==2)
cout<<"Grapes"<<endl;
if(a[x-1][y-1]==3)
cout<<"Waste"<<endl;
}
}


