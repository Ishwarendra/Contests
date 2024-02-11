#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto erase = [&](auto &x, auto p)
    {
        x.erase(x.find(p));
    };

    std::multiset<int> width, candid;
    auto add = [&](int x)
    {
        width.emplace(x);
        auto it = width.find(x);
        auto next = std::next(it), prev = std::prev(it);

        erase(candid, *next - *prev - 1);
        candid.emplace(*it - *prev - 1);
        candid.emplace(*next - *it - 1);
    };

    auto remove = [&](int x)
    {
        auto it = width.find(x);
        auto next = std::next(it), prev = std::prev(it);

        erase(candid, *it - *prev - 1);
        erase(candid, *next - *it - 1);
        candid.emplace(*next - *prev - 1);
        width.erase(it);
    };

    auto good = [&](int mid)
    {
        width.clear(), candid.clear();
        width.emplace(0), width.emplace(n + 1);
        candid.emplace(n);

        for (int i = 0; i < mid; i++)
            add(a[i]);

        int ans = *std::prev(std::end(candid));
        for (int i = mid; i < n; i++)
        {
            remove(a[i - mid]);
            add(a[i]);
            ans = std::max(ans, *std::prev(std::end(candid)));
        }

        return ans >= mid;
    };

    int left = 1, right = n;
    int ans = 0;
    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    int optimal = std::sqrt(n - 1);

    std::cout << ans << "\n";
    std::cout << (ans == optimal ? "NO\n" : "YES\n");
    
    return 0;
}