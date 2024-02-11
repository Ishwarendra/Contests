#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void read(std::vector<int> &a)
{
    for (auto &x : a)
        std::cin >> x;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> l(n), r(n), c(n);
    read(l), read(r), read(c);

    std::sort(std::rbegin(c), std::rend(c));
    std::sort(std::begin(r), std::end(r));

    std::multiset m(std::begin(l), std::end(l));
    i64 ans = 0;

    std::vector<int> len;
    for (int i = 0; i < n; i++)
    {
        auto it = std::prev(m.upper_bound(r[i]));
        len.emplace_back(r[i] - *it);
        m.erase(it);
    }

    std::sort(std::begin(len), std::end(len));
    for (int i = 0; i < n; i++)
        ans += 1LL * len[i] * c[i];

    std::cout << ans << "\n";
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