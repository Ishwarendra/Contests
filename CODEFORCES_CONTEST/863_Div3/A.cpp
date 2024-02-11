#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, d;
    std::cin >> n >> d;

    std::string s;
    std::cin >> s;

    bool done = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] - '0' < d and !done)
        {
            std::cout << d;
            done = true;
        }
        std::cout << s[i];
    }

    if (!done)
        std::cout << d;
    std::cout << "\n";
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