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

    std::vector<int> a(n), b(n);
    int f = n, s = -1;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] == 1)
        {
            f = std::min(f, i);
            s = std::max(s, i);
        }
    }

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 and b[i] == 0)
        {
            std::cout << "NO\n";
            return;
        }
    }

    auto work = [&]()
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                assert(a[i] == 0 and b[i] == 1);
                if (f < i or s > i)
                {
                    f = std::min(f, i);
                    s = std::max(s, i);
                }
            }
        }
    };

    work(); work();
    
    if (a.front() != b.front() or a.back() != b.back())
    {
        std::cout << "NO\n";
        return;
    }
    
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] != b[i])
        {
            if (f < i or s > i);
            else
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
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