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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];


    while (q--)
    {
        i64 x;
        std::cin >> x;

        auto id = std::upper_bound(std::begin(a), std::end(a), x) - std::begin(a);
        std::cout << id << "\n";
    }
    
    return 0;
}