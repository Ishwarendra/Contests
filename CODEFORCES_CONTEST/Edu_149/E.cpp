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
    
    int k;
    std::cin >> k;

    int n = 1 << k;
    std::vector<int> a(n), pos(n, -1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] != -1)
            pos[--a[i]] = i;
    }

    for (int num = 2; num < k; num++)
    {

    }

    return 0;
}