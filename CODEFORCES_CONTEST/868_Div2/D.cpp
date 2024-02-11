#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector a(k, std::array{0, 0});
    for (int i = 0; i < k; i++)
        std::cin >> a[i][0];
    for (int i = 0; i < k; i++)
        std::cin >> a[i][1];

    for (int i = 0; i < k; i++)
    {
        bool cond1 = a[i][1] > a[i][0];
        bool cond2 = i and a[i][0] - a[i - 1][0] < a[i][1] - a[i - 1][1];
        bool cond3 = a[i][0] <= 3 and a[i][0] != a[i][1];
     
        if (cond1 or cond2 or cond3)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::string ans = "abc", s = "abc";
    std::array<int, 2> prev {3, 3};
    int offset = -1;

    for (int i = a[0][0] == 3, pos = 0; i < k; i++)
    {
        int to_add = a[i][0] - prev[0];
        int diff = a[i][1] - prev[1];

        if (diff > to_add)
        {
            std::cout << "NO\n";
            return;
        }

        while (to_add > diff)
            ans += s[pos], pos = (pos + 1) % 3, to_add--;

        offset += (to_add > 0);
        while (to_add)
        {
            ans += char('a' + 3 + offset);
            to_add--, diff--;
        }

        prev = a[i];
    }

    std::cout << "YES\n" << ans << '\n';
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