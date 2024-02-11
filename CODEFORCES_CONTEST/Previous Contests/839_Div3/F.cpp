#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto f(char a, char b, char c, char d, char ch)
{
    return a == b and b == c and c == d and d == ch;
}

int count(std::vector<std::string> &a)
{
    int n = std::ssize(a);
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int m = std::ssize(a[i]);
        for (int j = 1; j < m - 1; j++)
            ans += f(a[i - 1][j], a[i][j - 1], a[i + 1][j], a[i][j + 1], ('0' + '1' - a[i][j]));
    }

    return ans;
}

std::vector<std::array<int, 2>> changed_positions(std::vector<std::string> &a, std::vector<std::string> &b)
{
    std::vector<std::array<int, 2>> pos;
    int n = std::ssize(a), m = std::ssize(a[0]);

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (a[i][j] != b[i][j])
                pos.push_back({i, j});
        }
    }

    return pos;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<std::vector<std::string>, int>> a(k + 1);
    for (int i = 0; i <= k; i++)
    {
        a[i].second = i + 1;
        a[i].first.resize(n + 1);

        for (int j = 0; j < n; j++)
            std::cin >> a[i].first[j];
    }

    std::sort(std::begin(a), std::end(a), 
        [&](auto &x, auto &y)
        {
            return count(x.first) > count(y.first);
        });

    std::cout << a[0].second << "\n";
    std::vector<std::vector<int>> ans;

    for (int i = 1; i <= k; i++)
    {
        auto pos = changed_positions(a[i - 1].first, a[i].first);
        if (pos.empty())
            ans.push_back({2, a[i].second});
        else
        {
            for (auto [x, y] : pos)
                ans.push_back({1, x + 1, y + 1});

            ans.push_back({2, a[i].second});
        }
    }   

    std::cout << std::ssize(ans) << "\n";
    for (auto p : ans)
    {
        for (auto i : p)
            std::cout << i << " ";
        std::cout << '\n';
    }

    return 0;
}