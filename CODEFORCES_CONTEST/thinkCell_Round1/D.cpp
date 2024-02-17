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
    std::cin >> n;

    std::string s;
    std::cin >> s;

    auto get = [&](std::string s)
    {
        int m = std::size(s);
        std::vector<std::pair<int, int>> a;

        int cnt = 1;
        for (int i = 1; i < m; i++)
        {
            if (s[i] == s[i - 1])
                cnt++;
            else
            {
                a.emplace_back(cnt, s[i - 1] - '0');
                cnt = 1;
            }
        }

        a.emplace_back(cnt, s.back() - '0');

        int ans = 0;
        int done = 0;

        for (auto &[c, ch] : a)
        {
            if (ch == 0)
            {
                done -= c;
                if (done < 0)
                    done = 0;
                continue;
            }

            int change = (c - done + 2) / 3;
            done += change * 3 - c;
            ans += change;
        }

        return ans;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            ans += get(s.substr(i, j - i + 1));
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