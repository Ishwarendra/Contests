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

    int sum = 0;
    std::array<int, 3> can{0, 0, 1};
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == -1 and a[i + 1] == -1)
        {
            can[0] = 1;
            a[i] = a[i + 1] = 1;
            break;
        }
        else if (a[i] != a[i + 1])
            can[1] = 1;
    }

    if (can[0] or can[1])
        std::cout << std::accumulate(std::begin(a), std::end(a), 0) << "\n";
    else
        std::cout << std::accumulate(std::begin(a), std::end(a), 0) - 2 - 2 << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}