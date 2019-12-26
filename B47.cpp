#include<bits/stdc++.h>
using namespace std;
int main()
{
int ca=0,cb=0,cc=0;
	int i;
string str;
	for(i=0;i<3;i++)
	{
		string comp;
		getline(cin>>ws,comp);
		
		if(comp=="A>B")
		{
		ca=ca+1;
		cb-=1;
		}
		if(comp=="A>C")
		{
		ca=ca+1;
		cc-=1;
		}
		if(comp=="B<A")
		{ca=ca+1;
		cb-=1;}
		if(comp=="C<A")
		{ca=ca+1;
		cc-=1;}
		if(comp=="B>A")
		{cb=cb+1;
		ca-=1;}
		if(comp=="B>C")
		{cb=cb+1;
		cc-=1;}
		if(comp=="A<B")
		{cb=cb+1;
		ca-=1;}
		if(comp=="C<B")
		{cb=cb+1;
		cc-=1;}
		if(comp=="C>A")
		{cc+=1;
		ca-=1;}
		if(comp=="C>B")
		{cc+=1;
		cb-=1;}
		if(comp=="A<C")
		{cc+=1;
		ca-=1;}
		if(comp=="B<C")
		{cc+=1;
		cb-=1;}
	}
	int l=0,l2=0,l3=0;
	for(i=-2;i<3;i+=2)
	{
		if(ca==i && l==0)
		{
		str+="A";
		l+=1;
		continue;
		}
		if(cb==i && l2==0)
		{
		str+="B";
		l2+=1;
		continue;
		}
		if(cc==i && l3==0)
		{
		str+="C";
		l3+=1;
		continue;
		}
	}
	if(!(l==1 && l2==1 && l3==1))
	cout<<"Impossible";
	else
	cout<<str;
}






