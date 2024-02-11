#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

bool powerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (n & (n - 1)) == 0;
}

void solve()
{
    int n, x;
    std::cin >> n >> x;

    if (powerOfTwo(n))
    {
        auto get = [](int p, int pos)
        {
            return (p >> pos) & 1;
        };

        int msb = std::__lg(n);
        if (!get(x, msb))
        {
            print(msb)
            std::cout << "-1\n";
            return;
        }
    }

    if (n == 2)
        std::cout << (x == 3 ? "1 1 2\n" : "-1\n");
    else
    {
        int max_ele = 0;
        for (int i = 1; i <= n; ++i)
            max_ele |= i;

        if (max_ele < x)
            std::cout << "-1\n";
        else
        {
            int cur = 3;
            for (int i = 4; i <= n; i++)
            {
                if (powerOfTwo(i))
                    continue;
                std::cout << "1 " << cur << " " << i << "\n";
                cur |= i;
            }

            int msb = std::__lg(x);
            int lim = 0;

            while ((1 << lim) <= n)
                lim++;

            print(cur)
            for (int i = lim - 1; i >= 0; i--)
            {
                if ((x >> i) & 1)
                {
                    std::cout << "1 " << cur << " " << (1 << i) << "\n";
                    cur |= (1 << );
                }
                else
                {
                    std::cout << "2 " << cur << " " << (1 << i) << "\n";
                    cur ^= (1 << i);
                }
            }

            print(cur, x)
        }
    }

    trace();
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