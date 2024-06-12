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
    i64 m;
    std::cin >> n >> m;

    std::vector<std::pair<i64, int>> a;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        std::cin >> x;
        a.emplace_back(x, i);
    }



    return 0;
}