#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,c=0,s=0;
	int i;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)

	cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		c++;
	}
	if(c>=k)
	{
		for(i=0;i<k;i++)
		a[i]*=-1;
	}
	if(c<k)
	{
		for(i=0;i<c;i++)
		a[i]*=-1;
		k=k-c;
		if(k%2!=0)
		{
			if(c<n)
			{
				if(a[c-1]>a[c])
				a[c]*=-1;
				else
				a[c-1]*=-1;
			}
			if(c==n)
			a[c-1]*=-1;
		}
	}
	for(i=0;i<n;i++)
	s+=a[i];
	cout<<s;
}
