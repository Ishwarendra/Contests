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

    std::vector<int> b(n / 2);
    std::set<int> notin;
    std::vector<int> count(n + 1);

    for (int i = 0; i < n / 2; i++)
    {
        std::cin >> b[i];
        count[b[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!count[i])
            notin.emplace(i);
    }

    if (*std::max_element(std::begin(count), std::end(count)) > 1)
    {
        std::cout << "-1\n";
        return;
    }

    std::map<int, int> partner;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        auto it = notin.upper_bound(b[i]);
        if (it != std::begin(notin))
            it--;
        else
        {
            std::cout << "-1\n";
            return;
        }

        partner[b[i]] = *it;
        notin.erase(it);
    }

    for (int i = 0; i < n / 2; i++)
    {
        auto [min, max] = std::minmax(b[i], partner[b[i]]);
        std::cout << min << " " << max << " \n"[i == n / 2 - 1];
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