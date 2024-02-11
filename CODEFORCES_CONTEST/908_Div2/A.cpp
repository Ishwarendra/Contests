#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::set<int> winners;
    int n;
    std::string s;
    std::cin >> n >> s;

    auto winner = [&](int x, int y)
    {
        std::array<int, 2> cnt{};
        std::array<int, 2> win{};

        for (int i = 0; i < n; i++)
        {
            int cur = s[i] - 'A';
            win[cur]++;
            if (win[cur] == x)
            {
                cnt[cur]++;
                win[0] = win[1] = 0;
            }

            if (cnt[cur] == y and i != n - 1)
                return -1;

            if (i == n - 1 and cnt[cur] != y)
                return -1;
        }

        if (cnt[0] == y and cnt[1] < y)
            return 0;
        if (cnt[0] < y and cnt[1] == y)
            return 1;

        return -1;
    };

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            int player = winner(x, y);
            if (player != -1)
                winners.emplace(player);
        }
    }

    if (std::size(winners) == 2)
        std::cout << "?\n";
    else
        std::cout << char(*std::begin(winners) + 'A') << "\n"; 
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