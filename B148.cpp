#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vp,vd,t,f,c,bij=0;
	double time,d,coorx=0,time2;
	cin>>vp;
	cin>>vd;
	cin>>t;
	cin>>f;
	cin>>c;
	coorx=vp*t;
	if(vd>vp)
	{
		if(vp*t==c)
		bij=0;
		for(; ;)
		{
			
			time=coorx/(vd-vp);
			coorx+=time*vp;
			if(coorx>=c)
			break;
			else
			{
				bij+=1;
				time2=coorx/vd;
				time2+=f;
				coorx+=time2*vp;
			}
		}
	}
	cout<<bij;
}

