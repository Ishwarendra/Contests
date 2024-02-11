#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> pref(n + 1), a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::multiset<int, std::greater<int>> m(std::begin(a), std::end(a));

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--;
        pref[l]++, pref[r]--;
    }

    for (int i = 1; i <= n; i++)
        pref[i] += pref[i - 1];

    std::multiset<std::pair<int, int>, std::greater<std::pair<int, int>>> p;
    for (int i = 0; i < n; i++)
        p.emplace(pref[i], i);

    i64 sum = 0;
    auto it = std::begin(m);
    for (auto [x, id] : p)
    {
        a[id] = *it;
        it++;
        sum += 1LL * x * a[id];
    }

    std::cout << sum << "\n";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];


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