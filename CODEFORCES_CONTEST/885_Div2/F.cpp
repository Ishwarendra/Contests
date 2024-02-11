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

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    auto good = [&](int mid)
    {
        auto b = a;
        
        for (int pos = 0; pos <= 20; pos++)
        {
            if (getBit(mid, pos))
            {
                auto c = b;
                for (int i = 0; i < n; i++)
                    b[i] ^= c[(i + (1 << pos)) % n];
            }
        }

        return b == std::vector(n, 0);   
    };

    int left = 0, right = n;
    int ans = -1;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}