#include<bits/stdc++.h>
using namespace std;
int main()
{
int r,c;
char ch;
cin>>r>>c>>ch;
char a[r][c];
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
cin>>a[i][j];
}
/*if(a[i][j]==ch)
{
in=i;
jn=j;
}
}
}
if(in>=1 && in<=r-2 && jn=1 && in<=c-2)
{*/

for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(a[i][j]==ch)
{
if(a[i-1][j]!='.' && a[i-1][j]!=ch && i-1>=0 &&i-1<n && j>=0 && j<n)
