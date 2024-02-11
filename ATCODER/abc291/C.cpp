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
    
    int n;
    std::string s;
    std::cin >> n >> s;

    std::set<std::pair<int, int>> vis;
    int x = 0, y = 0;
    vis.emplace(x, y);
    for (auto ch : s)
    {
        if (ch == 'L')
            x--;
        else if (ch == 'R')
            x++;
        else if (ch == 'U')
            y++;
        else
            y--;

        if (vis.count({x, y}))
        {
            std::cout << "Yes\n";
            return 0;
        }

        vis.emplace(x, y);
    }

    std::cout << "No\n";
    
    return 0;
}