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

    std::vector<int> w(n), x(n);
    for (int i = 0; i < n; i++)
        std::cin >> w[i] >> x[i];

    auto get = [&](int start)
    {
        i64 ans = 0;
        for (int i = 0; i < n; i++)
        {
            int time = (x[i] + start) % 24;
            if (9 <= time and time < 18)
                ans += w[i];
        }

        return ans;
    };

    i64 ans = 0;
    for (int i = 0; i < 24; i++)
        ans = std::max(ans, get(i));

    std::cout << ans;
    
    return 0;
}