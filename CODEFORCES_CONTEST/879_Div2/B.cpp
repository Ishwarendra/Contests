#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string l, r;
    std::cin >> l >> r;

    std::reverse(std::begin(l), std::end(l));
    while (std::size(l) != std::size(r))  
        l += '0';
    std::reverse(std::begin(l), std::end(l));

    int n = std::size(l);
    bool nine = false;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nine)
        {
            ans += 9;
            continue;
        }

        if (l[i] != r[i])
            ans += std::abs(l[i] - r[i]), nine = true;
    }   

    std::cout << ans << "\n";
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