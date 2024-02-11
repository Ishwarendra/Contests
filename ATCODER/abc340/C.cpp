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
    
    i64 n;
    std::cin >> n;

    std::map<i64, i64> m;
    auto f = [&](auto &&self, i64 x) -> i64
    {
        if (x < 2)
            return 0LL;

        if (m.contains(x))
            return m[x];

        return m[x] = self(self, x / 2) + self(self, (x + 1) / 2) + x;
    };

    std::cout << f(f, n);

    return 0;
}