#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,grp=1;
string str,str2;
cin>>n;
cin>>str;
for(i=1;i<n;i++)
{
cin>>str2;
if(str[1]==str2[0])
grp++;
str=str2;
}
cout<<grp;
}
