#include<bits/stdc++.h>
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define endl "\n"
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t,n,c,temp,A,B,C,D,w;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        A=n,B=0;C=-c;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            B+=temp;
            C+=temp*temp;
        }
        //w=(sqrt(B*B-A*C)-B)/(2*A);
        B/=(2*A);
        w=sqrt(B*B-C/(4*A))-B;
        cout<<w<<endl;
    }
    return 0;
}