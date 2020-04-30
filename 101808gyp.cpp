#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
double startTime;
double getCurrentTime()
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

// lli pwr(lli x,lli n)
// {
//     lli res=1;
//     for(; n!=0;n>>=1)
//     {
//         if(n&1)
//             res=(res*x)%MOD;
//         x=(x*x)%MOD;
//     }
//     return res;
// }
// lli inver(lli num)
// {
//     return pwr(num,MOD-2);
// }
// lli findncr(lli n,lli r)
// {
//     r=min(r,n-r);
//     if(n==0||n==1||r==0)
//         return 1;
//     lli numer=1;
//     for(lli i=n;i>=n-r+1;i--)
//         numer=(numer*i)%MOD;
//     lli den=1;
//     for(lli i=2;i<=r;i++)
//         den=(den*i)%MOD;
//     den=inver(den);
//     lli res=(numer*den)%MOD;
//     return res;
// }
lli gcd(lli a,lli b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
        #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    IOS
    int t;
   // cout<<"hell"<<" ";
    cin>>t;
    while(t--)
    {
        lli n,G,L;
        lli a[n]={0};
        cin>>n>>G>>L;
        fr2(i,n)
        {
            cin>>a[i];

        }
    if(L%G!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n==1)
        {
            if(L!=G) cout<<-1<<endl;
            else if(a[0]!=L) cout<<1<<endl;
            else
                cout<<0<<endl;
            continue;
        }
        vector<lli> preG(n,0);
          vector<lli> sufG(n,0);
         vector<lli> preL(n,0);
         vector<lli> sufL(n,0);
        fr(i,n )
        {
            if(!i)
            {
                preG[i]=a[i];
                preL[i]=a[i];
            }
            else
            {
                preG[i]=gcd(preG[i-1],a[i]);
                preL[i]=a[i]/gcd(a[i],preL[i-1])*preL[i-1];


            }
        }
        for(lli i=n-1 ;i>=0 ;i--)
        {
            if(i==n-1)
            {
                sufG[i]=a[i];
                sufL[i]=a[i];
            }
            else
            {
                sufG[i]=gcd(sufG[i+1],a[i]);
                sufL[i]=a[i]/gcd(a[i],sufL[i+1])*sufL[i+1];
            }
        }
        vector<int>invalid;
        fr(i,n)
        {
            if(a[i]>L) invalid.eb(i);
            else if (a[i]%G!=0 || L%a[i]!=0)
                invalid.eb(i);
        }
        if(sz(invalid)>1)
        {
            cout<<sz(invalid)<<endl;
            continue;
        }
        else if(sz(invalid)==0)
        {
            if(preG[n-1]==G && preL[n-1]==L)
            {
                cout<<0<<endl;
                continue;
            }
            else
            {
                int f=0;
                fr(i,n)
                {
                    lli g=0;
                    if(i) g=preG[i-1];
                    if(i+1<n) g=gcd(g,sufG[i+1]);
                    lli l=1;
                    if(i) l=preL[i-1];
                    if(i+1<n) l=l/gcd(l,sufL[i+1])*sufL[i+1];
                    if(gcd(g/G,L/l)==1)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                    cout<<1<<endl;
                else
                    cout<<2<<endl;


            }

        }
        else
        {
            lli i=invalid[0];
            lli g=0;
            if(i) g=preG[i-1];
            if(i+1<n) g=gcd(g,sufG[i+1]);
            lli l=1;
            if(i) l=preL[i-1];
            if(i+1<n) l=l/gcd(l,sufL[i+1])*sufL[i+1];
            if(gcd(g/G,L/l)==1) cout<<1<<endl;
            else
                cout<<2<<endl;
        }

    }
    startTime=(double)clock();
   // cout<<startTime<<" ";  
}
