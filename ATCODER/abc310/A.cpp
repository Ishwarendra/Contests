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

    int n, p, q;
    std::cin >> n >> p >> q;

    int min = 1e9;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        min = std::min(min, x);
    }

    std::cout << std::min(p, q + min);

    return 0;
}