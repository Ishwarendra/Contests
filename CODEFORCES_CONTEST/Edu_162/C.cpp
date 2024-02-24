#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<i64> psum(n), pone(n);
    for (int i = 0; i < n; i++)
    {
        psum[i] = a[i];
        pone[i] = a[i] == 1;

        if (i)
        {
            psum[i] += psum[i - 1];
            pone[i] += pone[i - 1];
        }
    }

    auto sum = [&](int l, int r, auto &p)
    {
        return p[r] - (l ? p[l - 1] : 0);
    };

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        i64 one = sum(l, r, pone);
        i64 have = sum(l, r, psum);

        i64 need = one * 2 + (r - l + 1 - one);
        std::cout << (need > have || l == r ? "NO\n" : "YES\n");
    }
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