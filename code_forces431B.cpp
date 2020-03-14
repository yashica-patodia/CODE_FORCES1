#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

// lli happy(int vec[5][5]);


int main()
{
	int k,i,j;
	lli max_h=0,h=0;

int vec[5][5];
	
	for(i=0;i<5;i++)
	{
		
		for(j=0;j<5;j++)
		{
			cin>>k;
			vec[i][j]=k;
			// cout<<vec[i][j];
		}
	}

	int a[]={1,2,3,4,5};
	lli s=0;
	do
	{
		s=0;
	
		for(i=0;i<4;i++)
	{

		if(i==0 || i==1)
		s+=vec[a[i]-1][a[1+i]-1]+vec[a[1+i]-1][a[i]-1]+vec[a[2+i]-1][a[3+i]-1]+vec[a[3+i]-1][a[2+i]-1];
	
		if(i==2 || i==3)
			s+=vec[a[i]-1][a[i+1]-1]+vec[a[i+1]-1][a[i]-1];
			// cout<<"s"<<s<<endl;



	}
		
		// cout<<h<<endl;
		max_h=max(s,max_h);
	}while(next_permutation(a,a+5));
	cout<<max_h;
}
