#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n), diff(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        diff[i] = x - a[i];
    }

    int sum = std::accumulate(std::begin(diff), std::end(diff), 0);

    if (sum == 0)
    {
        if (std::size(std::set(std::begin(diff), std::end(diff))) == 1)
            std::cout << "0\n";
        else
            std::cout << "1\n";
    }
    else
        std::cout << (std::count(std::begin(a), std::end(a), x) ? "1\n" : "2\n");
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