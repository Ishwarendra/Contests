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
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int can = 1;

    auto f = [&]()
    {
        for (int i = 0; i < n and can; i++)
        {
            if (b[i] < a[i])
                can = 0;
            else
            {
                if (a[i] == b[i] or b[(i + 1) % n] - b[i] >= -1)
                    a[i] = b[i];
                else
                    can = 0;
            }
        }
    }; f(); f();

    std::cout << (can ? "YES\n" : "NO\n");
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