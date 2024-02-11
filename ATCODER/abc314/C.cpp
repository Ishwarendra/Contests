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
    
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;

    std::vector<std::vector<int>> pos(m);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        pos[x - 1].emplace_back(i);
    }

    auto swap = [&](std::vector<int> &a)
    {
        if (a.empty())
            return;

        int sz = std::size(a);
        char first = s[a[sz - 1]];

        for (int i = sz - 2; i >= 0; i--)
            s[a[i + 1]] = s[a[i]];

        s[a[0]] = first;
    };

    for (int i = 0; i < m; i++)
        swap(pos[i]);

    std::cout << s;
    
    return 0;
}