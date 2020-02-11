#include<bits/stdc++.h>
using namespace std;
vector<set<int> >arr(1010);
set<int>::iterator it;
bool isPrime(int n)
{
    int s=sqrt(n);
    for(int i=2;i<=s;i++)
        if(n%i==0)
            return false;
    return true;
}
void prime_factor(int n)
{
    if(isPrime(n))
        return;
    int num=n;
    while (n%2==0)
    {
        n=n/2;
        arr[num].insert(2);
    }
    for (int i=3;i<=sqrt(n);i+=2)
        while (n%i==0)
        {
            arr[num].insert(i);
            n/=i;
        }
    if (n>2)
        arr[num].insert(n);
}
int main()
{
    vector<int>graph[1010],factor[1010];
    for(int i=1;i<1010;i++)
        prime_factor(i);
    for(int i=1;i<1010;i++)
        for(it=arr[i].begin();it!=arr[i].end();it++)
            factor[i].push_back(*it);
    for(int i=1;i<=1000;i++)
        for(int j=0;j<factor[i].size();j++)
            graph[i].push_back(i+factor[i][j]);
    int test,_case=0;
    cin>>test;
    while(test--)
    {
        int t,s;
        cin>>t>>s;
        cout<<"Case "<<++_case<<": ";
        if(t==s)
        {
            cout<<0<<endl;
            continue;
        }
        queue<int>qu;
        int level[1010],ans=-1;
        memset(level,-1,sizeof level);
        level[t]=0;
        qu.push(t);
        while(!qu.empty())
        {
            int x=qu.front();
            qu.pop();
            for(int i=0;i<graph[x].size();i++)
            {
                int y=graph[x][i];
                if(level[y]==-1)
                {
                    level[y]=level[x]+1;
                    qu.push(y);
                }
            }
        }
        cout<<level[s]<<endl;
    }
    return 0;
}

