#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int k, n;
    std::cin >> k >> n;

    for (int i = 1; i < n; i++)
    {
        std::vector<int> a(1, 1);
        for (int j = 0; j < i; j++)
            a.emplace_back(a.back() + 1);

        bool possible = true;

        for (int j = i + 1, cur = 2; j < k; j++, cur++)
        {
            a.emplace_back(a.back() + cur);
            if (a.back() > n)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            assert(std::ssize(a) >= k);
            for (int i = 0; i < k; i++)
                std::cout << a[i] << " \n"[i == k - 1];
            return;
        }
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