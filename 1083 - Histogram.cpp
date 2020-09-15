#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mx=3e4+10;
ll n,arr[mx];
pair<ll,ll> tree[4*mx];
void build(ll left,ll right,ll idx)
{
    if(left==right)
    {
        tree[idx].first=arr[left];
        tree[idx].second=left;
        return ;
    }
    ll mid=(left+right)/2;
    build(left,mid,idx*2+1);
    build(mid+1,right,idx*2+2);
    if(tree[idx*2+1].first<tree[idx*2+2].first)
    {
        tree[idx].first=tree[idx*2+1].first;
        tree[idx].second=tree[idx*2+1].second;
    }
    else
    {
        tree[idx].first=tree[idx*2+2].first;
        tree[idx].second=tree[idx*2+2].second;
    }
}
pair<ll,ll> query(ll left,ll right,ll ql,ll qr,ll idx)
{
    if(ql<=left && qr>=right)
        return tree[idx];
    if(ql>right || qr<left)
        return {INT64_MAX,INT64_MAX};
    ll mid=(left+right)/2;
    pair<ll,ll>p,q;
    p=query(left,mid,ql,qr,idx*2+1);
    q=query(mid+1,right,ql,qr,idx*2+2);
    return p.first<q.first?p:q;
}
ll func(ll st,ll ed)
{
    if(ed<st)
        return INT_MIN;
    if(ed==st)
        return arr[ed];
    pair<ll,ll> p=query(0,n-1,st,ed,0);
    ll xd=max(func(st,p.second-1),func(p.second+1,ed));
    return max(xd,(ed-st+1)*p.first);
}
int main()
{
    ll t,_case=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",arr+i);
        build(0,n-1,0);
        ll ans=func(0,n-1);
        printf("Case %lld: %lld\n",++_case,ans);
        memset(tree,0,sizeof tree);
    }
    return 0;
}