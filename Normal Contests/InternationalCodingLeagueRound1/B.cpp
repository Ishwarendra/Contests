#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> s(n), e(n);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    for (int i = 0; i < n; i++)
        std::cin >> e[i];

    std::vector<int> a(m);
    for (int i = 0; i < m; i++)
        std::cin >> a[i];

    std::vector<std::array<int, 3>> events;
    for (int i = 0; i < n; i++)
        events.push_back({s[i], -1, e[i]});
    for (int i = 0; i < m; i++)
        events.push_back({a[i], 1, a[i]});

    int sleep_end = -1;
    int ans = 0;

    std::sort(std::begin(events), std::end(events));
    for (auto &[st, type, en] : events)
    {
        if (type == -1)
            sleep_end = std::max(sleep_end, en);
        else
        {
            if (sleep_end < st)
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