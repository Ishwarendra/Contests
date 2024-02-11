#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

// LowerBound Finds the first position in which val could be inserted without changing the ordering.
// UpperBound Finds the last  position in which val could be inserted without changing the ordering.

ll summation(vector<ll> &a)
{
    ll sum = 0LL;
    for(ll i : a)
        sum += i;

    return sum;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> a(n, vector<ll>(n));
    vector<ll> median(n);

    for(int i = 0; i < n; i++)
    {
        vector<ll> tmp(n);
        for(int j = 0; j < n; j++)
        {
            cin >> tmp[j];
        }
        sort(tmp.begin(), tmp.end());
        a[i] = tmp;
        median[i] = tmp[(n + 2)/2];
    }    

    ll sum = summation(median);
    int ignore_idx = (n + 2)/2;

    // Search for minimum element if sum > k
    while(sum > k)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (j == ignore_idx)
                    continue;
                
            }
        }
    }
    
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}