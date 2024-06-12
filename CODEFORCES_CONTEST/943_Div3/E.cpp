#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Maximimse distinct manhattan distance
 * (n, n) and (1, i) => manhattan distance 2*n to n
 * (1, 1) to (1, i) => manhattan distance 1 to n - 1
 * But this needs n + 2 points
 * 
 * (2, 1) and (1, i) i >= 3
 * 3 to n - 1 covered.
 * (n, n) and (1, n - 1) covers distance n
 */

void solve()
{
    int n;
    std::cin >> n;
    
    if (n == 2)
    {
        std::cout << "1 1\n1 2\n";
        return;
    }
    
    std::vector<std::pair<int, int>> ans;
    for (int i = 1; i <= n - 1; i++)
    {
        if (i != 2)
            ans.emplace_back(1, i);
    }
    
    ans.emplace_back(2, 1);
    ans.emplace_back(n, n);
    
    assert(std::size(ans) == n);
    for (auto &[x, y] : ans)
        std::cout << x << " " << y << "\n";
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