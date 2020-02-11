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
        swap(n,m);
        char grid[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='@')
                    posr=i,posc=j;
            }
        int vis[25][25],dr[]={-1,1,0,0},dc[]={0,0,-1,1},cn=0;
        memset(vis,-1,sizeof vis);
        queue<pii>qu;
        qu.push(make_pair(posr,posc));
        vis[posr][posc]=1;
        while(!qu.empty())
        {
            pii x=qu.front();
            qu.pop();
            for(int i=0;i<4;i++)
            {
                int y=x.first+dr[i],z=x.second+dc[i];
                if(y>=0 && y<n && z>=0 && z<m)
                    if(grid[y][z]!='#' && vis[y][z]==-1)
                    {
                        cn++;
                        qu.push(make_pair(y,z));
                        vis[y][z]=1;
                    }
            }
        }
        cout<<"Case "<<++_case<<": ";
        cout<<cn+1<<endl;
    }
    return 0;
}
