#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9 + 10;

void chkmin(auto &a, auto b)
{
    if (b < a)
        a = b;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::array<int, 2> min {inf, inf};
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        chkmin(min[a[i] % 2], a[i]);
    }

    auto get = [&](int parity)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != parity)
            {
                int x = a[i] - min[1];
                if (x <= 0)
                    return false;
            }
        }

        return true;
    };

    std::cout << (get(0) || get(1) ? "YES\n" : "NO\n");
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