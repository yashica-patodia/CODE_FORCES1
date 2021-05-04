#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli n,i,c=0,s=1,lastpos,period;
	cin>>n;
	lli arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=0;i<n;i++)
	{
		if(c==0)
		{
		if(arr[i]==1)
		{
			c++;
			lastpos=i;
			period=0;

		}
	    }
	    else if(c>=1)
	    {
	    	c++;
	    	if(arr[i]==1)
	    	{
	    		period=i-lastpos;
	    		lastpos=i;
	    		s*=period;
	    	}

	    }



	}
	if(c==0)
		s=0;
	cout<<s;


}