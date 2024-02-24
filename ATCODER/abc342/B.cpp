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
    std::cin >> n;

    std::vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        pos[a - 1] = i;
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        std::cout << (pos[x] < pos[y] ? x + 1 : y + 1) << "\n";
    }
    
    return 0;
}