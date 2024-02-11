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
    
    int n, m, p;
    std::cin >> n >> m >> p;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - m >= 0 and (i - m) % p == 0)
            cnt++;
    }

    std::cout << cnt;
    
    return 0;
}