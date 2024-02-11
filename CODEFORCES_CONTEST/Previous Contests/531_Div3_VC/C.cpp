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
    
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].second;

        if (x >= a[i].second)
            a[i].first = (x - a[i].second) / y + 1;
        else
            a[i].first = 0;
    }

    std::sort(std::begin(a), std::end(a));
    int cnt = 0;
    int turn = 1;

    for (auto [num, f] : a)
    {
        if (num == 0 and x <= y)
            continue;
        if (num == 1 and x <= y)
        {
            cnt += turn;
            turn ^= 1;
        }
        else
            cnt++;
    }

    std::cout << cnt;
    
    return 0;
}