#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main()
{
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        int n,m,posr,posc;
        cin>>n>>m;
        char grid[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='h')
                    posr=i,posc=j;
            }

        ///2D greed BFS
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1},level[n][m];
        memset(level,-1,sizeof level);
        queue<pii>qu;
        level[posr][posc]=0;
        qu.push(make_pair(posr,posc));
        while(!qu.empty())
        {
            pii x=qu.front();
            qu.pop();
            int y=x.first,z=x.second;
            for(int i=0;i<4;i++)
            {
                int r=y+dr[i],c=z+dc[i];
                if(r>=0 && r<=n-1 && c>=0 && c<=m-1)
                    if(level[r][c]==-1 && grid[r][c]!='#' && grid[r][c]!='m')
                    {
                        level[r][c]=level[y][z]+1;
                        qu.push(make_pair(r,c));
                    }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='a' || grid[i][j]=='b' || grid[i][j]=='c')
                    ans=max(ans,level[i][j]);
            }
        cout<<"Case "<<++_case<<": ";
        cout<<ans<<endl;
    }
    return 0;
}

