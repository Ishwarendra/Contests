#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, b;
    std::cin >> n >> b;

    int ans = (1 << 30) - 1;
    int chosen = 0;
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        int ok = 1;
        for (int pos = 0; pos < 30; pos++)
        {
            if (getBit(b, pos) and !getBit(x, pos))
                ok = 0;
        }

        if (ok)
        {
            ans &= x;
            chosen = 1;
        }
    }

    if (!chosen)
        std::cout << "NO\n";
    else
        std::cout << (ans == b ? "YES\n" : "NO\n");
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