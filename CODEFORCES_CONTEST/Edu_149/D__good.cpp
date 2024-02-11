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
    std::string s;
    std::cin >> n >> s;

    n = std::size(s);
    std::vector<int> pos[2];
    for (int i = 0; i < n; i++)
        pos[s[i] == ')'].emplace_back(i);

    std::vector<int> ans(n, -1);
    
    if (std::size(pos[0]) != std::size(pos[1]))
    {
        std::cout << "-1\n";
        return;
    }

    auto f = [&](int col)
    {
        int i = 0, j = std::ssize(pos[1]) - 1;
        int ret = 0;
        while (i < n / 2 and j >= 0 and pos[0][i] < pos[1][j])
        {
            int x = pos[0][i], y = pos[1][j];
            if (ans[x] != -1)
            {
                i++;
                continue;
            }

            if (ans[y] != -1)
            {
                j--;
                continue;
            }

            ans[x] = col, ans[y] = col;
            ret = 1;
            i++, j--;
        }

        return ret;
    };

    int cnt = 0;
    cnt += f(1);
    std::swap(pos[0], pos[1]);
    cnt += f(2);

    std::cout << cnt << "\n";
    if (cnt == 1)
        std::fill(std::begin(ans), std::end(ans), 1);
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];

    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}