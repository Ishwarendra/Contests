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
    std::set<int> ignore;

    for (int i = 0; i < q; i++)  
    {
        int type;
        std::cin >> type;

        while (!blocked.empty() and std::begin(blocked)->first == i)
        {
            ignore.erase(std::begin(blocked)->second);
            blocked.erase(std::begin(blocked));
        }

        if (type == 1)
        {
            int pos;
            std::cin >> pos;
            pos--;

            blocked.emplace(i + t, pos);
            ignore.emplace(pos);
        }
        else if (type == 2)
        {
            int id1, pos1, id2, pos2;
            std::cin >> id1 >> pos1 >> id2 >> pos2;
            id1--, pos1--, id2--, pos2--;

            std::swap(s[id1][pos1], s[id2][pos2]);
        }
        else
        {
            int done = 0;
            for (int i = 0; i < std::size(s[0]); i++)
            {
                if (s[0][i] != s[1][i] and !ignore.count(i))
                {
                    done = 1;
                    std::cout << "NO\n";
                    break;
                }
            }

            if (!done)
                std::cout << "YES\n";
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