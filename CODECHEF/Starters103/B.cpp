#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    auto get = [&](int x)
    {
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            std::array<int, 2> cnt{};
            for (int j = i; j < n; j += k)
            {
                cnt[0] += s[j] == '0';
                cnt[1] += s[j] == '1';
            }

            if (x == 1)
            {
                if (cnt[1] == 0)
                    return inf;

                ans += cnt[0];
            }
            else
            {
                if (cnt[0] + cnt[1] == 1 and cnt[1] == 1)
                    return inf;
                ans += cnt[1] / 2 + (cnt[1] % 2) * 2;
            }
        }        

        return ans;
    };

    std::cout << std::min(get(0), get(1)) << "\n";
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