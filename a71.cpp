#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,k=0;
cin>>n;
string s;
vector<string> str2;
for(i=1;i<=n;i++)
{
cin>>s;
cout<<s<<endl;
if(s.length()>10)
{ 
string str=to_string(s.length()-2);
 string str3=s[0]+str+s[s.length()-1];
cout<<str3<<endl;
str2.push_back(str3);


}
else
str2[k++]=s;
cout<<str2[k-1]<<endl;
}
for(i=0;i<k;i++)
cout<<str2[i]<<endl;
}
