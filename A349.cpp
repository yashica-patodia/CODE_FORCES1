#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	int *arr;
	arr=new int[n];
	int *b;
	b=new int [3];
for(i=0;i<3;i++)
b[i]=0;
	for(i=0;i<n;i++)
	cin>>arr[i];
	int mon=0;
	int f=0;
	i=0;

	while(i<n)
	{


		if(arr[i]==25)
		{

			b[0]+=1;
			i++;
		}
		if(arr[i]==50)
		{
			if(b[0]>=1)
			{
			b[0]-=1;
			b[1]+=1;
			i++;
			}
			else
			{
			f=1;
			break;
			}
		}
		if(arr[i]==100)
		{
			if(b[0]>=1 && b[1]>=1)
			{
			b[0]-=1;
			b[1]-=1;
			b[2]+=1;
			i++;
			}
			else if(b[0]>=3 && b[1]==0)
			{
			b[0]-=3;
			b[2]+=1;
			i++;
			}
			else
			{
			f=1;
			break;
			}
		}
	}
	if(f==1)
	cout<<"NO";
	else
	cout<<"YES";
}

	
