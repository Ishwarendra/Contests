#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), s(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> s[i];

    std::multiset<int, std::greater<>> b(std::begin(s), std::end(s));
    for (int i = 0; i < n; i++)
    {
        while (!b.empty() and * std::begin(b) >= a[i])
        {
            std::cout << *std::begin(b) << " ";
            b.erase(std::begin(b));
        }

        std::cout << a[i] << " ";
    }

    while (!b.empty())
    {
        std::cout << *std::begin(b) << " ";
        b.erase(std::begin(b));
    }

    std::cout << "\n";
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