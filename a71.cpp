#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
string s[n];
string str2[n];
for(i=0;i<n;i++)
cin>>s[i];
for(i=0;i<n;i++)
{
if(s[i].length()>10)
{
string str=to_string(s[i].length()-2);
str2[i]=s[i].at(0)+str+s[i].at(s[i].length()-1);

}
else
str2[i]=s[i];
}
for(i=0;i<n;i++)
cout<<str2[i]<<endl;
}
