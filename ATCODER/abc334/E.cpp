#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

constexpr int MOD = 998244353;

template<class T>
T power(T a, T b, int mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
} 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    int den = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            std::cin >> ch;
            a[i][j] = ch == '#';
            den += !a[i][j];
        }
    }

    std::vector num(n, std::vector(m, 0));
    int cnt = 0;

    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < m;
    };

    auto dfs = [&](auto &&self, int x, int y) -> void
    {
        num[x][y] = cnt;
        for (auto &[dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy) || !a[x + dx][y + dy])
                continue;
            if (num[x + dx][y + dy])
                continue;

            self(self, x + dx, y + dy);
        }
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 0 and a[i][j])
            {
                cnt++;
                dfs(dfs, i, j);
            }
        }
    }

    int cc = cnt;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j])
                continue;

            std::set<int> s;
            for (auto &[dx, dy] : dirs)
            {
                if (!safe(i + dx, j + dy) || !a[i + dx][j + dy])
                    continue;

                s.emplace(num[i + dx][j + dy]);
            }

            ans = (ans + cc - std::ssize(s) + 1) % MOD;
        }
    }

    std::cout << (1LL * ans * power<i64>(den, MOD - 2, MOD)) % MOD;
        
    return 0;
}