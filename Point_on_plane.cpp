///solution for https://vjudge.net/problem/CodeForces-1809B
#include<iostream>
#include<fstream>
#include<vector>
#include<climits>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
long long x;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x;
        long long st=0;
        long long dr=2000000000;
        long long sol;
        int cnt=0;
        while(st<=dr)
        {
            long long mij=(st+dr)/2;
            unsigned long long rezz;
            if(mij%2==0)
            {
                rezz=1+mij/2*(mij/2+1)*4;
            }
            else {
                rezz=(mij+1)*(mij+1);
            } 
            if(rezz>=x)
            {
                sol=mij;
                dr=mij-1;
            }
            else st=mij+1;
        }
        cout<<sol<<'\n';
    }
}
