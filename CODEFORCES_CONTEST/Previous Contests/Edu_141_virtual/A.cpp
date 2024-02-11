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

    std::vector<int> a(n), m(101);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    std::set<int, std::greater<>> s(std::begin(a), std::end(a));
    std::vector<int> b;
    for (auto i : s)
        b.emplace_back(i);

    for (int i = 0; i < n; i++)
    {
        while (m[a[i]] > 1)
            b.emplace_back(a[i]), m[a[i]]--;
    }

    if (std::size(s) == 1)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++)
            std::cout << b[i] << " \n"[i == n - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}