#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If Alice decide to remove marbel-i
 *     Profit for Alice = a_i - 1
 *     Loss for Bob = b_i
 *     Total Score Gained = a_i - 1 + b_i
 *     
 * If Bob decide to remove marbel-i
 *     Profit for Bob = b_i
 *     Loss for Alice = a_i - 1
 *     Total Score Gained = a_i - 1 + b_i
 * 
 * Decide greedily based on a_i - 1 + b_i values!
 */

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    std::vector<std::tuple<int, int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        m.emplace_back(-(a[i] + b - 1), a[i], b);
    }
    
    std::sort(std::rbegin(m), std::rend(m));
    
    i64 ans = 0, turn = 1;
    while (!m.empty())
    {
        auto [_, a, b] = m.back();
        m.pop_back();
        ans += turn ? a - 1 : -b + 1;
        turn ^= 1;
    }
    
    std::cout << ans << '\n';
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