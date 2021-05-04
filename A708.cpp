#include<bits/stdc++.h>
using namespace std;
string encrypt(string s);

int main()
{
	string s;
	cin>>s;
	
		int start=0,end=0;
		while(s[start]=='a'&& start!=s.length()-1)
		start++;
		end=start;
		while(s[end]!='a' && end!=s.length())
		end++;
		if(start==end)
		end+=1;
		string str=s.substr(start,end-start);
		string str2=encrypt(str);


		s.replace(start,end-start,str2);
		cout<<s;
	
}

string encrypt(string s)
{
int i;
for(i=0;i<s.length();i++)
{
int k=(int)s[i];
if(k==97)
k=122;
else
k=k-1;
s[i]=(char)k;
}
return s;
}


