#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,*n,*x,*a,*b,*d,i;
cin>>t;
n=new int[t];
x=new int [t];
a=new int [t];
b=new int [t];
d=new int [t];
	
for(i=0;i<t;i++)
cin>>n[i]>>x[i]>>a[i]>>b[i];

	for(i=0;i<t;i++)
{
	 d[i]=abs(a[i]-b[i]);
	if(d[i]!=(n[i]-1))
	{
		int c=0;
		int g=(a[i]>b[i])?a[i]:b[i];
		int l=(a[i]<b[i])?a[i]:b[i];
		
		while(c<x[i] && abs(g-l)!=(n[i]-1))
		{
			if(g<=n[i])
			{g++;
			c++;
			}
		else if(g>n[i] && l>=1)
			{
			l--;
			c++;
			}
		}
		d[i]=abs(g-l);
	}
	else
	{
	         d[i]=abs(a[i]-b[i]);
	}
	
}
for(i=0;i<t;i++)
cout<<d[i]<<endl;
}
