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
        
    int cnt = 0;
    auto factor = [&](auto x, int limit = int(1e9))
    {
        std::vector<i64> s;
        for (int i = 1; 1LL * i * i <= x and i <= limit; i++)
        {
            cnt++;
            if (x % i == 0)
            {
                s.emplace_back(i);
                if (1LL * i * i != x and x / i <= limit)
                    s.emplace_back(x / i);
            }
        }

        return s;
    };

    factor(int(1e9));
    print(cnt * int(2e5))
    
    return 0;
}