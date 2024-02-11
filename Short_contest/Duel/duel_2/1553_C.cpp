#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = 10;
    int ans = 10;

    std::function<void(int, std::string &)> f = [&](int i, std::string & a)
    {
        if (i == n) 
        {
            int one = 0, two = 0;
            for (int i = 0; i < n; i++)
            {
                if (i % 2)
                    two += a[i] == '1';
                else
                    one += a[i] == '1';

                int rem = n - i - 1;
                if (one > two + (rem + 1) / 2 or two > one + rem / 2)
                {
                    ans = std::min(ans, i + 1);
                    return;
                }
            }

            return;
        }

        if (a[i] == '?')
        {
            a[i] = '1';
            f(i + 1, a);
            a[i] = '0';
            f(i + 1, a);
            a[i] = '?';
        }
        else
            f(i + 1, a);
    };

    std::string a = s;
    f(0, a);
    std::cout << ans << "\n";
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