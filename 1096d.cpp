#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+1;

string s,t="hard";
ll a[maxn],n;
ll memo[maxn][4];
ll go(ll i,ll j){
    if(i==n){
        if(j!=4) return 0;
        return 1e15;
    }
    if(j==4){
        return memo[i][j]=1e15;
    }
    if(memo[i][j]!=-1) return memo[i][j];
    ll ans=0;
    if(s[i]==t[j]){
        ans=ans+min(go(i+1,j+1),a[i]+go(i+1,j));
    }
    else{
        ans+=go(i+1,j);
    }
    return memo[i][j]=ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    cin>>n;
    cin>>s;
    memset(memo,-1,sizeof(memo));
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<go(0,0);
}