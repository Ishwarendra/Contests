#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto ok = [&](std::vector<int> b)
    {
        auto extrema = [&](int i)
        {
            int x = b[i - 1], y = b[i], z = b[i + 1];
            return (x < y and y > z) or (x > y and y < z);
        };

        for (int i = 1; i < n - 1; i++)
        {
            if (!extrema(i))
                return false;
        }

        return true;
    };

    std::sort(std::begin(a), std::end(a));
    auto make = [&](int st)
    {
        std::vector<int> b(n);
        int pos = 0;
        for (int i = st; i < n; i += 2)
            b[i] = a[pos++];
        for (int i = 1 - st; i < n; i += 2)
            b[i] = a[pos++];

        return b;
    };

    int ans = -1;
    if (ok(make(0)))
        ans = 0;
    else if (ok(make(1)))
        ans = 1;

    if (ans == -1)
        std::cout << "-1\n";
    else
    {
        for (const auto x : make(ans))
            std::cout << x << " ";
        std::cout << "\n";
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