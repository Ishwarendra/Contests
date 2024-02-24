#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> p[2];
    p[0] = p[1] = a;
    std::sort(std::begin(p[1]), std::end(p[1]));

    // keep two prefix sums
    // one for normal query another for sorted stone query
    for (int i = 1; i < n; i++)
    {
        p[0][i] += p[0][i - 1];
        p[1][i] += p[1][i - 1];
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int t, l, r;
        std::cin >> t >> l >> r;

        t--, l--, r--;
        std::cout << p[t][r] - (l ? p[t][l - 1] : 0) << "\n";
    }
    
    return 0;
}