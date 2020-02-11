#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll coin[60],val[60],n,k,dp[110][1110],vis[110][1110],call=0;
ll Knapsack(ll idx,ll total)
{
    ll j,ans=0;
    if(total==0)
        return 1;
    if(total<0 || idx>=n)
        return 0;
    if(vis[idx][total]==1)
        return dp[idx][total];
    vis[idx][total]=1;
    for(j=0 ; j<=val[idx] && total-j*coin[idx]>=0 ; j++)
    {
        ans+=Knapsack(idx+1,total-j*coin[idx]);
        ans%=mod;
    }
    return dp[idx][total]=ans;
}
int main()
{
    ll t,_case=0;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        ll i;
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>coin[i];
        for(i=0;i<n;i++)
            cin>>val[i];
        cout<<"Case "<<++_case<<": ";
        cout<<Knapsack(0,k)<<endl;
    }
    return 0;
}
