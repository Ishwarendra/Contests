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
    
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;

    std::vector<std::tuple<int, int, char>> query(q);
    for (auto &[type, id, c] : query)
        std::cin >> type >> id >> c;

    int low = 0, up = 0, id = q;
    for (int i = q - 1; i >= 0; i--)
    {
        auto [t, x, c] = query[i];
        if (t == 1)            
            continue;

        low = t == 2;
        up = t == 3;
        id = i + 1;
        break;
    }

    for (int i = 0; i < id; i++)
    {
        auto [t, x, c] = query[i];
        if (t == 1)
            s[x - 1] = c;
    }

    if (low or up)
    {
        for (int i = 0; i < n; i++)
            s[i] = (low ? std::tolower(s[i]) : std::toupper(s[i]));
    }

    for (int i = id; i < q; i++)
    {
        auto [t, x, c] = query[i];
        s[x - 1] = c;
    }

    std::cout << s;
    
    return 0;
}