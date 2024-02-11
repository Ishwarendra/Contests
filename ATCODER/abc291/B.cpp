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
    
    std::cout << std::fixed << std::setprecision(12);

    int n;
    std::cin >> n;

    std::multiset<int> m;
    for (int i = 0; i < 5 * n; i++)
    {
        int x;
        std::cin >> x;
        m.emplace(x);
    }

    for (int i = 0; i < n; i++)
        m.erase(std::begin(m));
    for (int i = 0; i < n; i++)
        m.erase(--std::end(m));

    i64 sum = std::accumulate(std::begin(m), std::end(m), 0LL);

    std::cout << 1.0L * sum / 3 / n << "\n";
    
    return 0;
}