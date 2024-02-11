#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> he(3), wi(3);

    for (int i = 0; i < 3; ++i)
        std::cin >> he[i];
    for (int i = 0; i < 3; ++i)
        std::cin >> wi[i];

    auto any_neg = [&](std::vector<int> &a)
    {
        for (int i : a)
            if (i <= 0)
                return true;

        return false;
    };

    auto ok = [&](std::vector<std::vector<int>> &a)
    {
        for (int i = 0; i < 3; i++)
        {
            int s = 0;
            for (int j = 0; j < 3; j++)
                s += a[i][j];

            if (s != he[i])
                return false;
        }

        for (int j = 0; j < 3; j++)
        {
            int s = 0;
            for (int i = 0; i < 3; i++)
                s += a[i][j];

            if (s != wi[j])
                return false;
        }


        return true;
    };

    long long cnt = 0;

    for (int a = 1; a <= 28; a++)
    {
        for (int b = 1; b <= 28; b++)
        {
            for (int d = 1; d <= 28; d++)
            {
                for (int e = 1; e <= 28; e++)
                {
                    int c = he[0] - a - b;
                    int f = he[1] - d - e;
                    int g = wi[0] - a - d;
                    int h = wi[1] - b - e;
                    int i = wi[2] - c - f;

                    std::vector<std::vector<int>> t =
                    {{a, b, c}, {d, e, f}, {g, h, i}};

                    std::vector<int> t2 = {a, b, c, d, e , f, g, h, i};
                    if (any_neg(t2))
                        continue;

                    if (!ok(t))
                        continue;

                    cnt++;
                }
            }
        }
    }

    std::cout << cnt << "\n";

    return 0;
}