#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int k;
    std::string s;
    std::cin >> k >> s;

    if (k == 1)
        std::cout << "YES\n";
    else
    {
        std::string res;
        int start = 3;
        while (std::size(res) < 50)
        {
            if (start % 3 == 0)
                res += 'F';
            if (start % 5 == 0)
                res += 'B';
            start++;
        }

        for (int i = 0; i < std::size(res); i++)
        {
            for (int j = i; j < std::size(res); j++)
            {
                if (res.substr(i, j - i + 1) == s)
                {
                    std::cout << "YES\n";
                    return;
                }
            }
        }

        std::cout << "NO\n";
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