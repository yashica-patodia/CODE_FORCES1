#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int *a;
	a=new int[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	int m;
	cin>>m;
	long int  *v;
	v=new long int[m];
	for(i=0;i<m;i++)
	v[i]=0;
	int *b;
	b=new int[n];
	for(i=0;i<n;i++)
	b[i]=a[i];

	int k=0;
	for(i=0;i<m;i++)
	{
		int t,l,r;
		cin>>t>>l>>r;
		if(t==1)
		{
			l=l-1;
			r=r-1;
			for(j=l;j<=r;j++)
			v[k]+=a[j];
			k++;
		}
		if(t==2)
		{
			l=l-1;
			r=r-1;
			sort(b,b+n);
			for(j=l;j<=r;j++)
			v[k]+=b[j];
			k++;
		}
	}
	for(i=0;i<m;i++)
	cout<<v[i]<<endl;
}



