#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		char  mat[n+1][m+1];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				mat[i][j]='B';
		}
		mat[0][0]='W';
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				cout<<mat[i][j];
			cout<<endl;
		}

	}
}