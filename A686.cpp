#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,x,c=0,i,want,fre=0;
string s,str;
cin>>n>>x;
c=x;
for(i=0;i<n;i++)
{
cin>>s;
/*if(s[0]=='+')
{
str=s.substr(2);
cout<<str;
c+=stoi(str);
}
else if(s[0]=='-')
{
str=s.substr(2);
want=stoi(str);
if(c>=want)
c-=want;
else
fre+=1;
}*/
cout<<s.substr(2);
}
cout<<c<<" "<<fre;
}
