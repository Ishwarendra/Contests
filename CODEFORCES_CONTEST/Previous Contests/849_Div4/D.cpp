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

    std::vector cnt(n, std::vector(26, 0));

    for (int i = 0; i < n; i++)
    {
        cnt[i][s[i] - 'a']++;
        if (i)
        {
            for (int j = 0; j < 26; j++)
                cnt[i][j] += cnt[i - 1][j];
        }
    }

    int ans = std::size(std::set(std::begin(s), std::end(s)));
    for (int i = 0; i < n - 1; i++)
    {
        std::vector<int> freq(26);
        for (int j = 0; j < 26; j++)
            freq[j] = cnt.back()[j] - cnt[i][j];

        int cur_ans = 0;
        for (int j = 0; j < 26; j++)
            cur_ans += cnt[i][j] > 0;

        for (int j = 0; j < 26; j++)
            cur_ans += freq[j] > 0;

        ans = std::max(ans, cur_ans);
    }

    std::cout << ans << "\n";
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