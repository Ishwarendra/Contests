#include <bits/stdc++.h>

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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int l;
        std::cin >> l;
        a[i].resize(l);

        for (int j = 0; j < l; ++j)
            std::cin >> a[i][j];
    }

    while (q--)
    {
        int s, t;
        std::cin >> s >> t;

        std::cout << a[s - 1][t - 1] << "\n";
    }
    
    return 0;
}