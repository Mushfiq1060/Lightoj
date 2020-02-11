/*
    author: Mushfiq Us Salehine
    institute: IIUC
    date: 31 Dec,2019
    time: 7:15pm
*/
///with segment tree
#include<bits/stdc++.h>
#define ll long long
#define _size 4000100
#define INF 1e12
using namespace std;
ll arr[_size],seg_tree[_size];
void construct_tree(ll left,ll right,ll pos)
{
    if(left==right)
    {
        seg_tree[pos]=arr[left];
        return ;
    }
    ll mid=(left+right)/2;
    construct_tree(left,mid,2*pos+1);
    construct_tree(mid+1,right,2*pos+2);
    seg_tree[pos]=min(seg_tree[2*pos+1],seg_tree[2*pos+2]);
}
ll RMQ(ll q_left,ll q_right,ll left,ll right,ll pos)
{
    if(q_left>right || q_right<left)
        return INF;
    if(q_left<=left && q_right>=right)
        return seg_tree[pos];
    ll mid=(left+right)/2;
    ll p,q;
    p=RMQ(q_left,q_right,left,mid,2*pos+1);
    q=RMQ(q_left,q_right,mid+1,right,2*pos+2);
    return min(p,q);
}
int main()
{
    ll t,_case=0;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,query,i,x,y;
        scanf("%lld %lld",&n,&query);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        construct_tree(0,n-1,0);
        printf("Case %lld:\n",++_case);
        while(query--)
        {
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",RMQ(x-1,y-1,0,n-1,0));
        }
    }
    return 0;
}
