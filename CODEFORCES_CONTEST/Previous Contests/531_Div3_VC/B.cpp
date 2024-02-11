#include <bits/stdc++.h>

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
    
    int n, k;
    std::cin >> n >> k;

    std::map<int, std::vector<int>> pos;
    int col = 0;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        pos[x].push_back(i);
    }

    for (auto [num, p] : pos)
    {
        if (std::size(p) > k)
        {
            std::cout << "NO\n";
            return 0;
        }
        else
        {
            for (int id : p)
            {
                a[id] = col + 1;
                col = (col + 1) % k;
            }
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];
    
    return 0;
}