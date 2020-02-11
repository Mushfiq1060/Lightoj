#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[500][500],n,dp[500][500];
bool vis[500][500];
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>arr[i][j];
    for(int i=n+1,k=n-1;i<2*n;i++,k--)
        for(int j=1;j<=k;j++)
            cin>>arr[i][j];
}
ll Knapsack(ll i,ll j)
{
    ll p,q;
    if(arr[i][j]==0)
        return 0;
    if(vis[i][j])
        return dp[i][j];
    vis[i][j]=1;
    if(i<n)
    {
        p=Knapsack(i+1,j)+arr[i][j];
        q=Knapsack(i+1,j+1)+arr[i][j];
    }
    else
    {
        p=Knapsack(i+1,j)+arr[i][j];
        q=Knapsack(i+1,j-1)+arr[i][j];
    }
    return dp[i][j]=max(p,q);
}
int main()
{
    ll t,_case=0;
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof arr);
        memset(vis,0,sizeof vis);
        read();
        cout<<"Case "<<++_case<<": ";
        cout<<Knapsack(1,1)<<endl;
    }
    return 0;
}
