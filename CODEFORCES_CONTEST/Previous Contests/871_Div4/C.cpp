#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    std::map<std::string, int> m;
    m["01"] = m["10"] = m["11"] = inf;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)  
    {
        int t;
        std::string s;
        std::cin >> t >> s;

        m[s] = std::min(m[s], t);
    }

    int ans = std::min(m["11"], m["01"] + m["10"]);
    std::cout << (ans < inf ? ans : -1) << "\n";
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