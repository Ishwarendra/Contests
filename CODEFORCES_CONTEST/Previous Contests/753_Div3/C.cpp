#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);

    for(ll &x : a) cin >> x;

    sort(a.begin(), a.end());
    
    ll old_min = a[0], new_min = a[0], additional = a[0];
    
        // cout << new_min << " " << old_min << " " << additional << "\n";
    for(int i = 1; i < n; i++)
    {
        new_min = max(old_min, a[i] - additional);
        additional = a[i];
        old_min = new_min;
        // cout << new_min << " " << old_min << " " << additional << "\n";
    }

    cout << new_min << "\n";

}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}