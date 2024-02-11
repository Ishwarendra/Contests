#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> pos[3];
    std::string s;
    for (int i = 1; i <= 3 * n; i += 3)  
    {
        for (int j = 0; j < 3; j++)
            pos[j].emplace_back(i + j);

        s += "BAN";
    }

    int j = std::ssize(pos[0]) - 1;
    int i = 0;

    std::vector<std::pair<int, int>> ans;
    while (i < j)
        ans.emplace_back(pos[1][j--], pos[0][i++]);

    if (n % 2)
        ans.emplace_back(pos[1][i], pos[2][0]);
    
    std::cout << std::size(ans) << "\n";
    for (auto [x, y] : ans)
        std::cout << x << " " << y << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}