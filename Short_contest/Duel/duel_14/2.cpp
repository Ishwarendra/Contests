#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int query(std::string &s)
{
    std::cout << "? " << s << std::endl;
    int len;
    std::cin >> len;
    return len;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector edges(m, std::array<int, 2>());
    std::string s(m, '0');
    for (int i = 0; auto &[w, id] : edges)
    {
        s[i] = '1';
        w = query(s);
        s[i] = '0';
        id = i++;
    }

    std::sort(std::begin(edges), std::end(edges));
    int ans = 0;

    for (auto &[w, id] : edges)
    {
        s[id] = '1';
        auto cur = query(s);
        // cur edge sum + extra edge == total then add 

        if (ans + w == cur)
            ans += w;
        else
            s[id] = '0';
    }

    std::cout << "! " << ans << std::endl;
    
    return 0;
}