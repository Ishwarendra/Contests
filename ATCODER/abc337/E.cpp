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
    std::cin >> n;

    int m = std::__lg(n);
    if ((1 << m) != n)
        m++;

    std::cout << m << std::endl;
    std::vector<std::vector<int>> query(m);

    for (int i = 0; i < n; i++)
    {
        for (int pos = 0; pos < m; pos++)
        {
            if ((i >> pos) & 1)
                query[pos].emplace_back(i);
        }
    }

    for (auto p : query)
    {
        std::cout << std::size(p) << " ";
        for (int i = 0; i < std::size(p); i++)
            std::cout << p[i] + 1 << " ";
        std::cout << std::endl;
    }

    std::string s;
    std::cin >> s;

    int x = 0;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == '1')
            x |= 1 << i;
    }

    std::cout << x + 1 << std::endl;

    return 0;
}