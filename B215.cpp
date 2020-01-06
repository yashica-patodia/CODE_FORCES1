#include<bits/stdc++.h>
using namespace std;
typedef double lli;
int main()
{
int n,m,k,i,a,b;
cin>>n;
int r1[n];
for(i=0;i<n;i++)
cin>>r1[i];
cin>>m;
int p1[m];
for(i=0;i<m;i++)
cin>>p1[i];
cin>>k;
int p2[k];
for(i=0;i<k;i++)
cin>>p2[i];
cin>>a>>b;
sort(r1,r1+n);
sort(p1,p1+m);
sort(p2,p2+k);

 lli ar1=r1[n-1];
lli ap1=p1[m-1];
lli ap2=p2[0];
lli ak=(a*ap2)/(b*ap1);
ak=sqrt(ak+1);
lli r2=ar1/ak;
cout<<fixed<<setprecision(12)<<r2;
}

