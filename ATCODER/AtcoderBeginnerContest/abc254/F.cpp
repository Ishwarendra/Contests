#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;



int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, q;
    std::cin >> n >> q;

    std::vector<std::vector<i64>> a(n, std::vector<i64>(n));
    std::vector<i64> t(n), t2(n);

    for (i64 i = 0; i < n; ++i)
        std::cin >> t[i];

    for (i64 i = 0; i < n; ++i)
        std::cin >> t2[i];

    for (i64 i = 0; i < n; ++i)
        for (i64 j = 0; j < n; ++j)
            a[i][j] = t[i] + t2[j];
    
    return 0;
}   