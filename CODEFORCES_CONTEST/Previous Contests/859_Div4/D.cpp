#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
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
    {
        std::cin >> a[i];
        a[i] %= 2;
    }

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    int odd = a.back();

    while (q--)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--, r--;

        int old = a[r] - (l == 0 ? 0 : a[l - 1]);
        int neww = (k % 2 ? r - l + 1 : 0);

        int have = odd - old + neww;
        std::cout << (have % 2 ? "YES\n" : "NO\n");
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}