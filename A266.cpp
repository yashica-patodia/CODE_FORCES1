#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,c=0,i;
cin>>n;
string s;
cin>>s;
for(i=0;i<n-1;i++)
{
if(s[i]==s[i+1])
c++;
}
cout<<c;
}


