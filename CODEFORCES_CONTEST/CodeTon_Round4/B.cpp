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

    if (n % 2 == 0)
        std::cout << "-1\n";
    else
    {
        std::vector<int> ans;
        while (n != 1)
        {
            if ((n / 2) % 2 == 0)
                ans.emplace_back(1), n = n / 2 + 1;
            else
                ans.emplace_back(2), n = n / 2;
        }

        std::reverse(std::begin(ans), std::end(ans));
        std::cout << std::size(ans) << "\n";
        for (auto x : ans) std::cout << x << " ";
        std::cout << "\n";
    }
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