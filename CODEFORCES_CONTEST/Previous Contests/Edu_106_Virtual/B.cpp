#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::ssize(s);

    int one = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1] and s[i] == '1')
        {
            one = i;
            break;
        }
    }

    int zero = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if (s[i] == s[i - 1] and s[i] == '0')
        {
            zero = i;
            break;
        }
    }

    if (one == -1 or zero == -1 or one >= zero)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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