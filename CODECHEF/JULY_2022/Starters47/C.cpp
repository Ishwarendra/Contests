#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::string a;

    std::cin >> n >> a;

    if (n <= 1)
    {
        std::cout << "YES\n";
        return;
    }

    if (a[0] != a[1])
    {
        std::cout << "NO\n";
        return;
    }

    auto check = [&](std::string & s)
    {
        int n = std::size(s);
        n -= n % 2;

        int possible = 1;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[i + n / 2])
                possible = 0;
        }

        return possible;
    };

    int can = 1;

    int len = n;
    while (len and can)
    {
        auto s = a.substr(0, len);
        can &= check(s);
        len /= 2;
    }

    std::cout << (can ? "YES\n" : "NO\n");
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