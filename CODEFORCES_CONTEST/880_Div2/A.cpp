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

    std::set<int> s;
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        s.emplace(x);
        m[x]++;
    }

    int need = 0;
    while (s.count(need))
        need++;

    if (s.lower_bound(need) == std::end(s))
    {
        for (int i = 1; i < need; i++)
        {
            if (m[i] > m[i - 1])
            {
                std::cout << "NO\n";
                return;
            }
        }

        std::cout << "YES\n";
    }
    else
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