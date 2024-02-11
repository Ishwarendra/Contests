#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    std::vector<std::set<int>> adj(26);

    for (int i = 0; i < std::size(s); i++)
        adj[s[i] - 'a'].emplace(i);

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int pos;
            char ch;
            std::cin >> pos >> ch;

            pos--;
            adj[s[pos] - 'a'].erase(pos);
            adj[ch - 'a'].emplace(pos);
            s[pos] = ch;
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;

            int ans = 0;
            for (int i = 0; i < 26; i++)
            {
                // auto it = std::lower_bound(std::begin(adj[i]), std::end(adj[i]), l);
                auto it = adj[i].lower_bound(l);
                if (it != std::end(adj[i]) and *it <= r)
                    ans++;
            }

            std::cout << ans << "\n";
        }
    }
    
    return 0;
}