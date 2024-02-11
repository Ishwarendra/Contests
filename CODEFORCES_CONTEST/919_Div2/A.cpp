#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int L = -1e9 + 1, R = 1e9 + 1;
    std::vector<int> no;
    for (int i = 0; i < n; i++)
    {
        int t, a;
        std::cin >> t >> a;

        if (t == 1)
            L = std::max(L, a);
        if (t == 2)
            R = std::min(R, a);
        if (t == 3)
            no.emplace_back(a);
    }

    std::sort(std::begin(no), std::end(no));
    int rem = std::upper_bound(std::begin(no), std::end(no), R)
         - std::lower_bound(std::begin(no), std::end(no), L);

    std::cout << std::max(0, R - L + 1 - rem) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}