#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            pos.emplace_back(i);
    }

    if (pos.empty())
        std::cout << "YES\n";
    else if (std::size(pos) == 2)
        std::cout << (std::abs(pos[0] - pos[1]) == 1 ? "NO\n" : "YES\n");
    else
        std::cout << (std::size(pos) % 2 ? "NO\n" : "YES\n");
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