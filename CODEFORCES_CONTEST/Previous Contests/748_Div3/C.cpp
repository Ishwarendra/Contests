#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    ll n, k; cin >> n >> k;
    vector<ll> x(k);
    
    int ans = 0;
    for(int i = 0; i < k; i++)
        cin >> x[i];

    sort(x.begin(), x.end(), greater<int>());
    // for(auto i : x)
    //     cout << i << " ";
    int cnt = 0, id = 0;
    while (id < k and cnt < n and ans <= k)
    {a
        cnt += (n - x[id]);
        // cout << cnt << endl;
        id++;
        if (cnt < n and ans <= k)
            ans++;
    }

    cout << ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}