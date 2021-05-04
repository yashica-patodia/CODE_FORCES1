#include<bits/stdc++.h>
using namespace std;
int main()
{
int i,k=0;
string s,t;
cin>>s;
cin>>t;
for(i=0;i<t.length();i++)
{
if(t[i]==s[k])
k++;
}
cout<<k+1;
}
