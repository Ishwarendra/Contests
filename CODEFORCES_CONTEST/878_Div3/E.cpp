#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<std::string, 2> s;
    std::cin >> s[0] >> s[1];

    int t, q;
    std::cin >> t >> q;

    std::set<std::pair<int, int>> blocked;
    std::set<int> unequal, blocked_nd_uneq;

    for (int i = 0; i < std::size(s[0]); i++)
    {
        if (s[0][i] != s[1][i])
            unequal.emplace(i);
    }

    for (int i = 0; i < q; i++)  
    {
        int type;
        std::cin >> type;

        while (!blocked.empty() and std::begin(blocked)->first == i)
        {
            auto [x, y] = *std::begin(blocked);
            blocked_nd_uneq.erase(y);
            blocked.erase(std::begin(blocked));
        }

        if (type == 1)
        {
            int pos;
            std::cin >> pos;
            pos--;

            blocked.emplace(i + t, pos);
            if (s[0][pos] != s[1][pos])
            {
                unequal.emplace(pos);
                blocked_nd_uneq.emplace(pos);
            }
            else
                unequal.erase(pos);
        }
        else if (type == 2)
        {
            int id1, pos1, id2, pos2;
            std::cin >> id1 >> pos1 >> id2 >> pos2;
            id1--, pos1--, id2--, pos2--;

            std::swap(s[id1][pos1], s[id2][pos2]);

            if (s[0][pos1] == s[1][pos1])
                unequal.erase(pos1);
            else
                unequal.emplace(pos1);

            if (s[0][pos2] == s[1][pos2])
                unequal.erase(pos2);
            else
                unequal.emplace(pos2);
        }
        else
        {
            if (std::size(unequal) == std::size(blocked_nd_uneq))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
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