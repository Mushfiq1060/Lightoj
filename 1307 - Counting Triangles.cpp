#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,_case=0;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],num,pos,cn=0;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                num=arr[i]+arr[j];
                pos=upper_bound(arr,arr+n,num-1)-arr-1;
                cn+=(pos-j);
            }
        cout<<"Case "<<++_case<<": ";
        cout<<cn<<endl;
    }
    return 0;
}
