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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    if (a.front() == a.back())
        std::cout << "-1\n";
    else
    {
        std::vector<int> b, c;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a.back())
                c.emplace_back(a[i]);
            else
                b.emplace_back(a[i]);
        }

        std::cout << std::size(b) << " " << std::size(c) << "\n";
        for (auto x : b)
            std::cout << x << " ";
        std::cout << '\n';
        for (auto x : c)
            std::cout << x << " ";
        std::cout << '\n';
    }
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