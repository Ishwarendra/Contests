#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    if (n == 3)
        std::cout << "2 3 6\n";
    else
    {
        for (int i = n; i > 0; i -= 4)
        {
            if (i == 1)
                std::cout << "1 ";
            else if (i == 2)
                std::cout << "1 2 ";
            else if (i == 3)
                std::cout << "1 2 3 ";
            else
            {
                i -= 3;
                std::cout << i * (i + 3) << " " << (i + 2) * i << " " << (i + 3) * (i + 1) <<
                          " " << (i + 2) * (i + 1) << " ";
                i += 3;
            }
        }

        std::cout << "\n";
    }
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