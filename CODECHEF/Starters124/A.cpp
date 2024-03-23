#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> pos(26);
    for (int i = 0; i < std::size(s); i++)  
        pos[s[i] - 'a'].emplace_back(i);

    int n = std::size(s);
    auto get = [&](std::vector<int> &a)
    {
        int sz = std::size(a);
        std::vector<int> p(n);
        for (int i = 0; i < sz; i++)
            p[a[i]] = 1;

        for (int i = 1; i < n; i++)
            p[i] += p[i - 1];

        int ans = sz;
        for (int i = 0; i + sz - 1 < n; i++)
        {
            int cur = p[i + sz - 1] - (i ? p[i - 1] : 0);
            ans = std::min(ans, sz - cur);
        }

        return ans;
    };

    int ans = n;
    for (int i = 0; i < 26; i++)
    {
        if (!pos[i].empty())
            ans = std::min(ans, get(pos[i]));
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