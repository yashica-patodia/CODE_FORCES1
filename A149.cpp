#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,i,sum=0;
	cin>>k;
	int *a;
	int n=12,f=0;
	a=new int [n];
	for(i=0;i<n;i++)
	cin>>a[i];
	if(k!=0)
	{
		int c=0;
		sort(a,a+n,greater<int>());
		for(i=0;i<n;i++)
		{
			c++;
			sum+=a[i];
			if(sum>=k)
			{
			f=1;
			break;
			}
		}

		if(f==1)
		cout<<c;
		else
		cout<<-1;
	}
	else
	cout<<0;
}

