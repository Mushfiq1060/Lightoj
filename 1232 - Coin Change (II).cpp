#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll n,k,arr[110],dp[110][10100];
bool vis[110][10100];
ll Knapsack(ll idx,ll total)
{
    ll ans=0;
    if(total==0)
        return 1;
    if(total<0 || idx==n)
        return 0;
    if(vis[idx][total])
        return dp[idx][total];
    vis[idx][total]=1;
    for(int j=0;j<=k && total-(j*arr[idx])>=0; j++)
    {
        ans+=Knapsack(idx+1,total-(j*arr[idx]));
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
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        memset(vis,0,sizeof vis);
        cout<<"Case "<<++_case<<": ";
        cout<<Knapsack(0,k)<<endl;
    }
    return 0;
}
