#include<bits/stdc++.h>
#define ll long long
#define _size 101000
using namespace std;
ll tree[_size];
void update(ll idx,ll val,ll n)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}
ll query(ll idx,ll sum)
{
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
int main()
{
    ll t,_case=0;
    scanf("%lld",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        ll i,n,q,a,num,x,y,sum1,sum2,p;
        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            update(i,a,n);
        }
        printf("Case %lld:\n",++_case);
        while(q--)
        {
            scanf("%lld",&num);
            if(num==1)
            {
                scanf("%lld",&x);
                sum1=query(x+1,0);
                sum2=query(x,0);
                p=sum1-sum2;
                printf("%lld\n",p);
                update(x+1,-p,n);
            }
            else if(num==2)
            {
                scanf("%lld %lld",&x,&y);
                update(x+1,y,n);
            }
            else
            {
                scanf("%lld %lld",&x,&y);
                sum1=query(y+1,0);
                sum2=query(x,0);
                printf("%lld\n",sum1-sum2);
            }
        }
    }
    return 0;
}
