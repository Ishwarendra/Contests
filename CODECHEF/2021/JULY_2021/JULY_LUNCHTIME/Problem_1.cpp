#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<long long>;
using ll = long long;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vi a(n);
        unordered_map<ll, ll> m;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }

        ll ans = 0;

        for(int i = 0; i < n; i++)
            ans += (n - m[a[i]]);
        
        cout << ans << '\n';
    }
    return 0;
}