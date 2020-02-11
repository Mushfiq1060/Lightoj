#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n][3];
        for(int i=0;i<n;i++)
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        for(int i=1;i<n;i++)
        {
            arr[i][0]+=min(arr[i-1][1],arr[i-1][2]);
            arr[i][1]+=min(arr[i-1][0],arr[i-1][2]);
            arr[i][2]+=min(arr[i-1][0],arr[i-1][1]);
        }
        cout<<"Case "<<++_case<<": ";
        cout<<min(arr[n-1][0],min(arr[n-1][1],arr[n-1][2]))<<endl;
    }
    return 0;
}
