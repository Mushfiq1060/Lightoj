#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main()
{
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char grid[n+5][n+5],ch='A',xd;
        map<char,pii>mp;
        map<char,pii>::iterator it;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]>='A' && grid[i][j]<='Z')
                    mp[grid[i][j]]={i,j};
            }
        cout<<"Case "<<++_case<<": ";
        if(mp.size()==1)
            cout<<0<<endl;
        else
        {
            bool vis[n][n];
            int level[n][n],cn=0;
            int dr[]={0,0,-1,1},dc[]={-1,1,0,0};
            for(it=mp.begin();it!=mp.end();++it)
                ch=max(ch,it->first);
            bool flag;
            for(xd='A';xd<ch;xd++)
            {
                int p=mp[xd].first,q=mp[xd].second;
                grid[p][q]='.';
                memset(vis,0,sizeof vis);
                memset(level,0,sizeof level);
                queue<pii>qu;
                qu.push(make_pair(p,q));
                vis[p][q]=1;
                level[p][q]=0;
                flag=false;
                while(!qu.empty())
                {
                    pii x=qu.front();
                    qu.pop();
                    for(int i=0;i<4;i++)
                    {
                        int y=x.first+dr[i],z=x.second+dc[i];
                        if((grid[y][z]=='.' || grid[y][z]==xd+1) && y>=0 && y<n && z>=0 && z<n)
                        {
                            if(vis[y][z]==0)
                            {
                                level[y][z]+=level[x.first][x.second]+1;
                                vis[y][z]=1;
                                if(grid[y][z]==xd+1)
                                    flag=true;
                                qu.push(make_pair(y,z));
                            }
                        }
                    }
                }
                if(!flag)
                    break;
                cn+=level[mp[xd+1].first][mp[xd+1].second];
            }
            if(!flag)
                cout<<"Impossible"<<endl;
            else
                cout<<cn<<endl;
        }
    }
    return 0;
}
