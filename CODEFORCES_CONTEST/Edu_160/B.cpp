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

    int n = std::size(s);
    int one = std::count(std::begin(s), std::end(s), '1');
    int zero = n - one;

    int ans = 0;
    for (int i = 0, cnt = 0; cnt < n; cnt++)
    {
        if (s[i] == '0')
        {
            if (one)
                one--, i++;
            else
                ans++;
        }
        else
        {
            if (zero)
                zero--, i++;
            else
                ans++;
        }
    }

    std::cout << ans << "\n";
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