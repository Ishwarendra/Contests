#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 30;

std::vector<std::string> getVector(int sz)
{
    std::vector<std::string> a(sz);
    for (int i = 0; i < sz; i++)
        std::cin >> a[i];
    return a;
}

int getCount(std::vector<std::string> &a)
{
    int ans = 0;
    for (auto s : a)
    {
        for (auto ch : s)
            ans += ch == '#';
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::array<int, 3> n{}, m{};

    std::cin >> n[0] >> m[0];
    auto a = getVector(n[0]);

    std::cin >> n[1] >> m[1];
    auto b = getVector(n[1]);

    std::cin >> n[2] >> m[2];
    auto c = getVector(n[2]);

    auto put = [&](int i1, int j1)
    {
        std::vector screen(3 * N, std::string(3 * N, '.'));
        for (int i = 0; i < n[0]; i++)
        {
            for (int j = 0; j < m[0]; j++)
                screen[i + N][j + N] = a[i][j];
        }

        for (int i = 0; i < n[1]; i++)
        {
            for (int j = 0; j < m[1]; j++)
            {
                if (b[i][j] == '#')
                    screen[i + i1][j + j1] = '#';
            }
        }

        if (getCount(screen) != getCount(c))
            return false;

        auto check = [&](int st, int en)
        {
            for (int i = 0; i < n[2]; i++)
            {
                for (int j = 0; j < m[2]; j++)
                {
                    if (screen[i + st][j + en] != c[i][j])
                        return false;
                }
            }

            return true;
        };

        for (int i = 0; i < 2 * N; i++)
        {
            for (int j = 0; j < 2 * N; j++)
            {
                if (check(i, j))
                    return true;
            }
        }

        return false;
    };

    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            if (put(i, j))
            {
                std::cout << "Yes";
                return 0;
            }
        }
    }

    std::cout << "No";
    
    return 0;
}