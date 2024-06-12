#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> pos(n), h(n);
    for (int i = 0; i < n; i++)
        std::cin >> pos[i];
    for (int i = 0; i < n; i++)
        std::cin >> h[i];
    
    std::vector<i64> kill(n), suff_min(n);
    std::vector<i64> gain(n);
    gain[0] = h[0];
    for (int i = 1; i < n; i++)
        gain[i] = gain[i - 1] + h[i];
    
    i64 used = 0;
    for (int i = 0; i < n; i++)
    {
        kill[i] = pos[i] - (h[i] + used);
        used += h[i]; 
    }

    auto sum = [&](int l, int r) -> i64
    {
        if (r < l)  
            return 0;
        return gain[r] - (l ? gain[l - 1] : 0);
    };
    
    suff_min[n - 1] = kill[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suff_min[i] = std::min(suff_min[i + 1], kill[i]);

    used = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 and used > pos[i - 1])
            break;

        int next = std::upper_bound(std::begin(pos), std::end(pos), pos[i] + 2 * k) - std::begin(pos);
        if (next >= n or suff_min[next] >= 0)
        {
            std::cout << "YES\n";
            return;
        }
        
        if (std::abs(suff_min[next]) <= sum(i, next - 1))
        {
            std::cout << "YES\n";
            return;
        }
        
        used += h[i];
    }
    
    std::cout << "NO\n";
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