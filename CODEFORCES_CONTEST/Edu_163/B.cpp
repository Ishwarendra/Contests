#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (std::is_sorted(std::begin(a), std::end(a)))
    {
        std::cout << "YES\n";
        return;
    }

    auto ok = [&](int id)
    {
        std::vector<int> b;
        for (int i = 0; i < id; i++)
        {
            int x = a[i];
            if (x < 10)
                b.emplace_back(x);
            else
                b.emplace_back(x / 10), b.emplace_back(x % 10);
        }

        for (int i = id; i < n; i++)
            b.emplace_back(a[i]);

        return std::is_sorted(std::begin(b), std::end(b));
    };

    int possible = 0;
    for (int i = 0; i <= n; i++)
        possible |= ok(i);

    std::cout << (possible ? "YES\n" : "NO\n");
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