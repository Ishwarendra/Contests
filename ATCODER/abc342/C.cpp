#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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

    std::vector<std::vector<int>> pos(26);
    for (int i = 0; auto &ch : s)
        pos[ch - 'a'].emplace_back(i++);

    int q;
    std::cin >> q;

    while (q--)
    {
        char x, y;
        std::cin >> x >> y;
        
        int c = x - 'a';
        int d = y - 'a';

        if (c == d)
            continue;

        if (std::size(pos[d]) > std::size(pos[c]))
        {
            pos[d].insert(std::end(pos[d]), std::begin(pos[c]), std::end(pos[c]));
            pos[c].clear();
        }
        else
        {
            pos[c].insert(std::end(pos[c]), std::begin(pos[d]), std::end(pos[d]));
            pos[d].clear();
            std::swap(pos[c], pos[d]);
        }
    }

    std::string ans(n, '.');
    for (int i = 0; i < 26; i++)
    {
        for (auto id : pos[i])
            ans[id] = char(i + 'a');
    }

    std::cout << ans;
    
    return 0;
}