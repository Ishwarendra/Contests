#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void rotate(auto &a)
{
    std::array<std::string, 4> s;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            s[3 - j] += a[i][j];
    }

    std::swap(s, a);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int n = 4;

    std::array<std::string, n> a, b, c;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    auto safe = [&](int x, int y)
    {
        return std::min(x, y) >= 0 and std::max(x, y) < n;
    };

    for (int db = 0; db < n; db++)
    {
        for (int dc = 0; dc < n; dc++)
        {
            for (int dxa = -3; dxa < n; dxa++)
            {
                for (int dya = -3; dya < n; dya++)
                {
                    for (int dxb = -3; dxb < n; dxb++)
                    {
                        for (int dyb = -3; dyb < n; dyb++)
                        {
                            for (int dxc = -3; dxc < n; dxc++)
                            {
                                for (int dyc = -3; dyc < n; dyc++)
                                {
                                    std::array<std::string, 4> s;
                                    for (int i = 0; i < n; i++)
                                        s[i] = "....";

                                    int ok = 1;
                                    auto cover = [&](auto & p, int dx, int dy)
                                    {
                                        if (!ok)
                                            return;

                                        for (int i = 0; i < n; i++)
                                        {
                                            for (int j = 0; j < n; j++)
                                            {
                                                if (p[i][j] == '.')
                                                    continue;

                                                int x = i + dx, y = j + dy;
                                                if (!safe(x, y) or s[x][y] == '#')
                                                {
                                                    ok = 0;
                                                    return;
                                                }
                                                else
                                                    s[x][y] = '#';
                                            }
                                        }
                                    };

                                    cover(a, dxa, dya);
                                    cover(b, dxb, dyb);
                                    cover(c, dxc, dyc);

                                    for (int i = 0; i < n; i++)
                                        ok &= (s[i] == "####");
                                    if (ok)
                                    {
                                        std::cout << "Yes";
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            rotate(c);
        }
        rotate(b);
    }

    std::cout << "No";

    return 0;
}