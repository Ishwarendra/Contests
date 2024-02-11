#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

bool valid(std::vector<int> &a)
{
    bool ok = true;
    for (int i = 0; i < std::size(a); i++)
    {
        int prev = 0, next = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[i])
                prev = 1;
        }

        for (int j = i + 1; j < std::size(a); j++)
        {
            if (a[j] > a[i])
                next = 1;
        }

        if (prev and next)
            ok = false;
    }

    return ok;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> ans(n);
    i64 max = 0;

    for (int id = 0; id < n; id++)
    {
        std::vector<int> cur = a;
        i64 sum = 0;

        for (int i = id - 1; i >= 0; i--)
            cur[i] = std::min(cur[i + 1], a[i]);
        for (int i = id + 1; i < n; i++)
            cur[i] = std::min(cur[i - 1], a[i]);

        sum = std::accumulate(std::begin(cur), std::end(cur), 0LL);
        if (sum > max)
        {
            max = sum;
            std::swap(ans, cur);
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];

    return 0;
}