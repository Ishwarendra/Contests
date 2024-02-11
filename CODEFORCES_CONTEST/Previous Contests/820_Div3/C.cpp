#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector<std::vector<int>> adj(26);

    for (int i = 0; i < n; ++i)
        adj[s[i] - 'a'].emplace_back(i);

    // s[0] to s[n - 1]
    if (s[0] == s[n - 1])
    {
        std::cout << "0 " << std::size(adj[s[0] - 'a']) << "\n";
        for (auto i : adj[s[0] - 'a'])
            std::cout << i + 1 << " ";
        std::cout << "\n";
    }
    else if (s[0] < s[n - 1])
    {
        i64 cost = s[n - 1] - s[0], jumps = 0;
        std::vector<int> ans;
        for (char ch = s[0]; ch <= s[n - 1]; ch++)
        {
            int i = ch - 'a';

            for (auto pos : adj[i])
            {
                ans.push_back(pos + 1);
                jumps++;
            }
        }

        std::cout << cost << " " << jumps << "\n";
        for (int i = 0; i < std::size(ans); ++i)
            std::cout << ans[i] << " ";
        std::cout << "\n";
    }
    else
    {
        i64 cost = s[0] - s[n - 1], jumps = 0;
        std::vector<int> ans;
        for (char ch = s[0]; ch >= s[n - 1]; ch--)
        {
            int i = ch - 'a';

            for (auto pos : adj[i])
            {
                ans.push_back(pos + 1);
                jumps++;
            }
        }

        std::cout << cost << " " << jumps << "\n";
        for (int i = 0; i < std::size(ans); ++i)
            std::cout << ans[i] << " ";
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