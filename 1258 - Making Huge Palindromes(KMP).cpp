/**
 * Idea is making a reverse string of string
 * string is str
 * reverse string is rev
 * so we find the longest prefix of rev as a substring of str
 * then result is 2*(length of str)-longest prefix which is match
 * IF prefix of a reverse string and suffix of a original string is match then the matching portion is palindromw
 **/
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    int t,_case=0;
    cin>>t;
    while(t--)
    {
        string str,rev;
        cin>>str;
        rev=str;
        reverse(rev.begin(),rev.end());
        int l=str.size(),i=1,j=0;
        int lps[l+10];
        lps[0]=0;
        while(i<l)
        {
            if(rev[i]==rev[j])
                lps[i]=j+1,i++,j++;
            else  
            {
                while(1)
                {
                    if(j==0)
                    {
                        lps[i]=(rev[i]==rev[j]);
                        i++;
                        break;
                    }
                    j=lps[j-1];
                    if(rev[i]==rev[j])
                    {
                        lps[i]=j+1;
                        i++,j++;
                        break;
                    }
                }
            }
        }
        i=0,j=0;
        while(i<l)
        {
            if(str[i]==rev[j]) 
                i++,j++;
            else  
            {
                while(1)
                {
                    if(j==0)
                    {
                        i++;
                        break;
                    }
                    j=lps[j-1];
                    if(str[i]==rev[j])
                    {
                        i++,j++;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<++_case<<": "<<2*l-j<<endl;
    }
    return 0;
}