#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x, y, n;
    std::cin >> x >> y >> n;

    std::vector<int> a(n);
    a.front() = x, a.back() = y;

    int d = 1;
    for (int i = n - 2; i >= 1; i--)
    {
        a[i] = a[i + 1] - d;
        d++;
    }

    auto ok = [&]()
    {
        std::vector<int> b;
        for (int i = 1; i < n; i++)
            b.emplace_back(a[i] - a[i - 1]);

        if (std::size(std::set(std::begin(b), std::end(b))) != std::size(b))
            return false;
        
        return std::is_sorted(std::begin(b), std::end(b), std::greater());
    };

    if (ok())
    {
        for (int i = 0; i < n; i++)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    else
        std::cout << "-1\n";
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