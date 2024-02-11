#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool all_same(vector<ll> v)
{
    int n = v.size();
    for(int i = 0; i < n - 1; i++)
    {
        if (v[i] != v[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            int x; cin >>x;
            a[i] = x - i;
        }
        
        if (all_same(a))
        {
            cout << n << "\n";
            return 0;
        }

        cout << 1 << "\n";
    }
    return 0;
}