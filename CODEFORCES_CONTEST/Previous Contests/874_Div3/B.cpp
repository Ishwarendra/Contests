#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i][0];
        a[i][1] = i;
    }

    std::sort(std::begin(a), std::end(a));
    std::vector<int> b(n), ans(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::sort(std::begin(b), std::end(b));

    for (int i = 0; i < n; i++)
        ans[a[i][1]] = b[i];

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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