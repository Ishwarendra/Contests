#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {
    {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::set<std::pair<int, int>> ans;
    auto f = [&](int i, int j)
    {
        for (auto [dx, dy] : dirs)
            ans.emplace(i + dx, j + dy);
    };

    int x = 0, y = 0;
    n++;
    while (n--)
    {
        f(x, y);
        x += 2, y += 2;
    }

    assert(std::ssize(ans) < int(5e5));
    std::cout << std::size(ans) << "\n";
    for (auto [i, j] : ans)
        std::cout << i << ' ' << j << "\n";
    
    return 0;
}