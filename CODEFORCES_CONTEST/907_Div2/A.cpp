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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int prev = 1, nex = 2;
    while (prev <= nex)
    {
        if (!std::is_sorted(std::begin(a) + prev, std::begin(a) + nex))
        {
            std::cout << "NO\n";
            return;
        }

        prev *= 2;
        nex *= 2;
        if (nex >= n)
            nex = n;
    }

    std::cout << "YES\n";
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