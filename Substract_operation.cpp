///https://vjudge.net/problem/CodeForces-1656B
#include<iostream>
#include<vector>
#include<algorithm>

#define FAST ios_base::sync_with_stdio(0) , cin.tie(0)

#define sortare(x) sort(x.begin(),x.end())

#define merge cout<<"YES"<<'\n'

#define nu_merge cout<<"NO"<<'\n'

using namespace std;


int main()
{
    FAST;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        bool da=false;

        vector<int>v(n);

        for(int i=0;i<n;i++)
        cin>>v[i];

        sortare(v);

        int st=0;
        int dr=1;

        while(st<n && dr<n)
        {
            if(v[st]+k==v[dr])
            {
                da=true;
                break;
            }
            else if(k+v[st]<v[dr])
            {
                st++;
            }
            else dr++;
        }
        if(da)
        merge;
        else nu_merge;
    }
}
