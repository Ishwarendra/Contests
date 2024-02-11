#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    if (n == 1)
        std::cout << "YES\n";
    else if (s[n - 1] == s[n - 2])
        std::cout << "NO\n";
    else
    {
        if (s.back() == '0')
        {
            for (auto &ch : s)
                ch = '0' ^ '1' ^ ch;
        }

        int zero = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1')
                zero++;
        }

        zero++;
        print(zero)
        if (std::count(std::begin(s), std::end(s) - 1, '1') <= zero)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}