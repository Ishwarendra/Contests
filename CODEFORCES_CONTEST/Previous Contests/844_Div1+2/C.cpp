#include "bits/stdc++.h"

#undef LOCAL

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

    std::pair<std::string, int> ans;
    ans.second = n;

    std::vector<int> cnt(26), pos[26];
    for (int i = 0; auto ch : s)
    {
        cnt[ch - 'a']++;
        pos[ch - 'a'].emplace_back(i++);
    }

    for (int i = 1; i <= 26; i++)
    {
        if (n % i)
            continue;

        int need = n / i;
        std::vector<std::pair<int, int>> a(26);
        for (int i = 0; i < 26; i++)
            a[i] = {cnt[i], i};

        std::sort(std::rbegin(a), std::rend(a));
        std::pair<std::string, int> cur_ans {s, 0};

        std::multiset<std::pair<int, char>> donor;
        for (int j = i; j < 26; j++)
        {
            if (a[j].first != 0)
                donor.emplace(a[j].first, s[a[j].second]);
        }

        
    }

    std::cout << ans.second << '\n' << ans.first << "\n";
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