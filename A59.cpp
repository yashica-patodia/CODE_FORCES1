#include<bits/stdc++.h>
using namespace std;
int main()
{
int i,up=0,low=0;
string s;
cin>>s;
for(i=0;i<s.length();i++)
{
if(isupper(s[i]))
up++;
if(islower(s[i]))
low++;
}
if(up>low)
transform(s.begin(),s.end(),s.begin(),::toupper);
if(up<=low)
transform(s.begin(),s.end(),s.begin(),::tolower);
cout<<s;
}

