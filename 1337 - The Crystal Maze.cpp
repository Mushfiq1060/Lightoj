#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main()
{
    int t,_case=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,q,u,v;
        scanf("%d %d %d",&n,&m,&q);
        char grid[n+5][m];
        int dp[n+5][m+5];
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf(" %c",&grid[i][j]);
        bool vis[n][m];
        memset(vis,0,sizeof vis);
        printf("Case %d:\n",++_case);
        while(q--)
        {
            scanf("%d %d",&u,&v);
            u--,v--;
            if(dp[u][v]==-1)
            {
                int dr[]={0,0,-1,1},dc[]={-1,1,0,0},cn=0;
                queue<pii>qu,mu;
                qu.push(make_pair(u,v));
                vis[u][v]=1;
                while(!qu.empty())
                {
                    pii x=qu.front();
                    qu.pop();
                    for(int i=0;i<4;i++)
                    {
                        int p=x.first+dr[i],q=x.second+dc[i];
                        if(grid[p][q]!='#' && p>=0 && p<n && q>=0 && q<m)
                            if(vis[p][q]==0)
                            {
                                vis[p][q]=1;
                                qu.push(make_pair(p,q));
                                if(grid[p][q]=='C')
                                    cn++;
                            }
                    }
                }
                memset(vis,0,sizeof vis);
                dp[u][v]=cn;
                mu.push(make_pair(u,v));
                vis[u][v]=1;
                while(!mu.empty())
                {
                    pii x=mu.front();
                    mu.pop();
                    for(int i=0;i<4;i++)
                    {
                        int p=x.first+dr[i],q=x.second+dc[i];
                        if(grid[p][q]!='#' && p>=0 && p<n && q>=0 && q<m)
                            if(vis[p][q]==0)
                            {
                                vis[p][q]=1;
                                mu.push(make_pair(p,q));
                                dp[p][q]=cn;
                            }
                    }
                }
            }
            printf("%d\n",dp[u][v]);
        }
    }
    return 0;
}
