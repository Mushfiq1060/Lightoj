#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>node[20020];
ll n,red=0,green=0,ans=0,vis[20020],color[20020];
void bfs()
{
    memset(vis,-1,sizeof vis);
    memset(color,-1,sizeof color);
    queue<ll>qu;
    for(int i=0;i<=20000;i++)
        if(node[i].size()!=0 && vis[i]==-1)
        {
            red=green=0;
            qu.push(i);
            vis[i]=1;
            while(!qu.empty())
            {
                ll x=qu.front();
                qu.pop();
                if(color[x]==-1)
                    color[x]=1,red++;
                for(ll i=0;i<node[x].size();i++)
                {
                    if(vis[node[x][i]]==-1)
                    {
                        if(color[x]==1 && color[node[x][i]]==-1)
                            color[node[x][i]]=2,green++;
                        else if(color[x]==2 && color[node[x][i]]==-1)
                            color[node[x][i]]=1,red++;
                        qu.push(node[x][i]);
                        vis[node[x][i]]=1;
                    }
                }
            }
            ans+=max(red,green);
        }
}
int main()
{
    ll t,_case=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll u,v;
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&u,&v);
            node[u].push_back(v);
            node[v].push_back(u);
        }
        bfs();
        printf("Case %lld: %lld\n",++_case,ans);
        for(int i=0;i<20020;i++)
            node[i].clear();
        ans=0;
    }
    return 0;
}
