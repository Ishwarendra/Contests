#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s, l, r;
    int m;
    std::cin >> s >> m >> l >> r;

    int n = std::size(s);

    if (n < m)
    {
        std::cout << "YES\n";
        return;
    }

    std::vector<int> pos[10];
    for (int i = 0; i < n; i++)
        pos[s[i] - '0'].emplace_back(i);
        
    int subseq = 1, prev = 0;
    std::string ans;
    for (int i = 0; i < m; i++)
    {
        int best = -1;
        int done = 0;
        for (int ch = l[i]; ch <= r[i]; ch++)
        {
            if (!subseq)
            {
                best = 0;
                done = 1;
                ans += ch;
                break;
            }

            int x = ch - '0';
            int id = std::lower_bound(std::begin(pos[x]), std::end(pos[x]), prev) - std::begin(pos[x]);
            
            if (id == std::size(pos[x]))
            {
                done = 1;
                subseq = false, ans += ch;
                best = 0;
                break;
            }

            best = std::max(best, pos[x][id]);
        }

        if (best == -1)
        {
            std::cout << "NO\n";
            return;
        }

        if (!done)
            ans += s[best], prev = best + 1;
    }

    std::cout << (subseq ? "NO\n" : "YES\n");
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