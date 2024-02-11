#include<bits/stdc++.h>
#define yes cout<<"Yes"<<"\n"
#define no cout<<"No"<<"\n"
#define endl "\n"
#define int long long
using ll=long long;
using namespace std;

int solve()
{
    int n,m,d,ans=0,sum=0,temp,count=0,i=0;
    vector<int>vec;
    cin>>n>>m>>d;
    cin>>temp;
    sum-=d,i++;
    if(temp>0)
    {
        sum+=temp;
        vec.push_back(temp);
        ans=max(ans,sum);
        count++;
    }
    for(;count<m&&i<n;i++)
    {
        sum-=d;
        cin>>temp;
        if(temp>0)
        {
            vec.push_back(temp);
            sum+=temp;
            ans=(ans<sum)?sum:ans;
            count++;
        }
    }
    sort(vec.begin(),vec.end());
    for(;i<n;i++)
    {
        sum-=d;
        cin>>temp;
        if(temp>vec[0])
        {
            sum+=temp-vec[0];
            vec[0]=temp;
            ans=max(ans,sum);
            sort(vec.begin(),vec.end());
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // std::freopen("in.in", "r", stdin);
    // std::freopen("out.out", "w", stdout);

    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<endl;
    }

    std::cerr << "Time elapsed: " << 1000. * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}

