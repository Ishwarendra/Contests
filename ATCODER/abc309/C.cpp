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
    
    int n, k;
    std::cin >> n >> k;

    std::map<int, i64, std::greater<>> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        m[x] += y;
    }

    for (auto it = std::next(std::begin(m)); it != std::end(m); it++)
        m[it->first] += m[std::prev(it)->first];

    for (auto [x, s] : m)
    {
        if (s > k)
        {
            std::cout << x + 1;
            return 0;
        }
    }

    std::cout << 1;
    
    return 0;
}