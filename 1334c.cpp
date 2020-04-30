#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	lli t,n,a,b,i;
	cin>>t;
	while(t--)
	{
		vector<pair<int,int> >vec;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a>>b;
			vec.push_back(make_pair(a,b));


		}
		int index=0;
		for(i=1;i<n;i++)
		{
			if(vec[i].first<vec[index].first)
				index=i;
		}
		
		lli bul=vec[index].first;
		lli harm=vec[index].second;
		i=index;
			while( i<(n-1))
			{
				i++;
				if(vec[i].first-harm<=0)
				{
					harm=vec[i].second;
				}
				else
				{
					lli hel=vec[i].first-harm;
					bul+=hel;
					harm=vec[i].second;
				}
				// harm=vec[i].second;

				
			}
			i=0;
			while(i<index)
			{
				if(vec[i].first-harm<=0)
				{
					harm=vec[i].second;
				}
				else
				{
					lli hel=vec[i].first-harm;
					bul+=hel;
					harm=vec[i].second;
				}
				i++;
			}
			cout<<bul<<endl;

		}


	

}