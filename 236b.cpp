#include<bits/stdc++.h>
using namespace std;
//int divi(int n);
/*int main()
{
	int a,b,c,i,j,k;
	long long int s=0;
	cin>>a>>b>>c;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			for(k=1;k<=c;k++)
			{
				s+=divi(i*j*k);
			}
		}
	}
	cout<<s;
}*/
int main()
{
	int n;
	cin>>n;
	int i=2,c=0;
	while(n!=1 && i<=n)
	{
		if(n%i==0)
		{
			c++;
			n/=i;
		}
		i++;

	}
	cout<<c+1;
}