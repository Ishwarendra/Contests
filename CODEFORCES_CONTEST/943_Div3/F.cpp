#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Divide into subarrays with xor = xr
 * { xr ... xr .. xr} (k = odd)
 * 
 * Divide into two parts where each part has some xor
 * { xr ... xr } total 0 (k = even)
 */

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] ^= p[i - 1] ^ a[i];

    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++)
        pos[p[i]].emplace_back(i);

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        int xr = p[r] ^ (l ? p[l - 1] : 0);

        if (xr == 0)
        {
            if (r - l + 1 < 2)
                std::cout << "NO\n";
            else
                std::cout << "YES\n";
        }
        else
        {
            int st = (l ? p[l - 1] : 0);
            auto id1 = std::lower_bound(std::begin(pos[xr ^ st]), std::end(pos[xr ^ st]), l);
            
            int f = id1 == std::end(pos[xr ^ st]) ? n : *id1;
            auto id2 = std::upper_bound(std::begin(pos[st]), std::end(pos[st]), f);
            
            if (id2 == std::end(pos[st]) or *id2 >= r)
                std::cout << "NO\n";
            else
                std::cout << "YES\n";
        }
    }

    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}