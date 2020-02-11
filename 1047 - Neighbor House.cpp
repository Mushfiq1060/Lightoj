#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[30][5],n,dp[30][5];
bool vis[30][5];
int func(int i,int j)
{
    int p=0,q=0;
    if(i==n-1)
        return arr[i][j];
    if(vis[i][j]==1)
        return dp[i][j];
    vis[i][j]=1;
    if(j==0)
    {
        p=func(i+1,j+1)+arr[i][j];
        q=func(i+1,j+2)+arr[i][j];
    }
    else if(j==1)
    {
        p=func(i+1,j-1)+arr[i][j];
        q=func(i+1,j+1)+arr[i][j];
    }
    else if(j==2)
    {
        p=func(i+1,j-1)+arr[i][j];
        q=func(i+1,j-2)+arr[i][j];
    }
    return dp[i][j]=min(p,q);
}
int main()
{
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof vis);
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                cin>>arr[i][j];
        cout<<"Case "<<++_case<<": ";
        cout<<min(func(0,0),min(func(0,1),func(0,2)))<<endl;
    }
    return 0;
}
