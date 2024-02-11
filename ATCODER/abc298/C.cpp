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
    std::cin >> n >> q;

    std::vector<std::multiset<int>> box(n + 1);
    std::map<int, std::set<int>> m; 

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int i, j;
            std::cin >> i >> j;
            box[j].emplace(i);
            m[i].emplace(j);
        }
        else if (t == 2)
        {
            int i;
            std::cin >> i;

            for (auto x : box[i])
                std::cout << x << " ";
            std::cout << "\n";
        }
        else
        {
            int i;
            std::cin >> i;

            for (auto x : m[i])
                std::cout << x << " ";
            std::cout << "\n";
        }
    }
    
    return 0;
}