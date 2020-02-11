#include<bits/stdc++.h>
#define ll long long
using namespace std;
double Radian(double a)
{
    return (a*acos(-1.0))/180.00;
}
int main()
{
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        double R,n,r,angle;
        cin>>R>>n;
        angle=Radian(360/(2*n));
        r=(R*sin(angle))/(1+sin(angle));
        cout<<"Case "<<++_case<<": ";
        printf("%.10lf\n",r);
    }
    return 0;
}
