#include<bits/stdc++.h>
using namespace std;
int prime[30],fact[110][110];
bool check[110];
void find_prime()
{
    int i,j;
    for(i=2;i*i<=100;i++)
        for(j=i*i;j<=100;j+=i)
            check[j]=true;
    for(i=2,j=0;i<=100;i++)
        if(!check[i])
            prime[j++]=i;
}
void prime_factor(int n)
{
    int i,p=n;
    for(i=0;i<25;i++)
        while(n%prime[i]==0)
        {
            fact[p][prime[i]]++;
            n/=prime[i];
        }
}
int main()
{
    find_prime();
    memset(fact,0,sizeof(fact));
    int i,j;
    for(i=2;i<=100;i++)
        prime_factor(i);
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans[n+1],k=0,pos;
        memset(ans,0,sizeof(ans));
        for(i=2;i<=n;i++)
            for(j=2;j<=n;j++)
                ans[j]+=fact[i][j];
        for(i=0;i<=n;i++)
            if(ans[i])
                pos=i;
        cout<<"Case "<<++_case<<": "<<n<<" = ";
        for(i=0;i<=n;i++)
            if(ans[i])
            {
                if(i!=pos)
                    cout<<i<<" ("<<ans[i]<<") * ";
                else
                    cout<<i<<" ("<<ans[i]<<")";
            }
        cout<<endl;
    }
    return 0;
}
