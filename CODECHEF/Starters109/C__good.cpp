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

    std::multiset<int, std::greater<>> even, odd;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        (x % 2 ? odd : even).emplace(x);
    }

    int o = std::size(odd), e = std::size(even);
    if (o % 2 or e % 2)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> b;

    for (int i = 0; i < 2; i++)
    {
        int cnt = o / 2;
        while (cnt--)
        {
            b.emplace_back(*std::begin(odd));
            odd.erase(std::begin(odd));
        }

        cnt = e / 2;
        while (cnt--)
        {
            b.emplace_back(*std::begin(even));
            even.erase(std::begin(even));
        }
    }

    std::vector<int> a;
    for (int i = 0; i < n / 2; i++)
    {
        int x = b[i], y = b[i + n / 2];
        a.emplace_back((x + y) / 2);
        a.emplace_back(x - a.back());
    }

    std::sort(std::rbegin(a), std::rend(a));

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
    // i64 sum = std::accumulate(std::begin(a), std::begin(a) + n / 2, 0LL);
    // sum *= 2;
    // assert(sum == std::accumulate(std::begin(b), std::end(b), 0LL));
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