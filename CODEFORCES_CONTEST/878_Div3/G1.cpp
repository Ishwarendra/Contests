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
    
    int x;
    std::cin >> x;

    std::map<int, int> dist;
    int d = 0;
    for (int i = 0; i <= 1010; i++)
    {
        std::cout << "+ 1" << std::endl;
        int x;
        std::cin >> x;

        if (dist.count(x))
        {
            std::cout << "! " << d << "\n";
            return 0;
        }
        else
            dist[x] = ++d;
    }

    for (int i = 0; i <= 1010; i++)
    {
        std::cout << "+ 1000" << std::endl;
        int x;
        std::cin >> x;

        d += 1000;
        if (dist.count(x))
        {
            std::cout << "! " << d - dist[x] << "\n";
            return 0;
        }
        else
            dist[x] = d;
    }

    assert(false);
    
    return 0;
}