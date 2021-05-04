#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
string s;
cin>>s;
int a=0;
for(i=0;i<n;i++)
{
if(s[i]=='A')
a+=1;
}
int k=n-a;

if(k>a)
cout<<"Danik";
if(k<a)
cout<<"Anton";
if(k==a)
cout<<"Friendship";
}
