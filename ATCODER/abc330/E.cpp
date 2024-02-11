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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto erase = [&](auto &p, int x)
    {
        auto it = p.find(x);
        if (it != std::end(p))
            p.erase(it);
    };

    std::multiset<int> m;
    for (int i = 0; i <= n + 1; i++)
        m.emplace(i);

    std::map<int, int> f;
    for (int i = 0; i < n; i++)
    {
        f[a[i]]++;
        erase(m, a[i]);
    }

    while (q--)
    {
        int id, x;
        std::cin >> id >> x;
        id--;

        f[a[id]]--;
        if (f[a[id]] == 0)
            m.emplace(a[id]);
        a[id] = x;
        f[x]++;
        erase(m, x);

        std::cout << *std::begin(m) << "\n";
    }
    
    return 0;
}