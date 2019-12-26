#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,j,k;
	cin>>n;
	int *a;
	a=new int[n];
	int i,v=0,p=0;
	for(i=0;i<n;i++)
	cin>>a[i];
	int m;
	cin>>m;
	int *b;
	b=new int[m];
	for(i=0;i<m;i++)
	cin>>b[i];

	int t=m;
	for(i=0;i<t;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i]==a[j])
			{
				v+=1;
				break;
			}
				v+=1;
		}
		for(k=n-1;k>=0;k--)
		{
			if(b[i]==a[k])
			{
				p+=1;
				break;
			}
			p+=1;
		}
	}
	cout<<v<<" "<<p;
}
