#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x, y;
    std::cin >> x >> y;

    std::vector<int> a;

    for (int i = x; i > y; i--)
        a.emplace_back(i);
    for (int i = y; i < x; i++)
        a.emplace_back(i);

    std::cout << std::size(a) << "\n";
    for (int i = 0; i < std::ssize(a); i++)
        std::cout << a[i] << " \n"[i + 1 == std::ssize(a)];
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