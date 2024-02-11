#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s, t;
    std::cin >> s >> t;

    std::vector<int> cnt(26);
    for (auto &ch : t)
        cnt[ch - 'a']++;

    std::map<int, int> m;
    for (auto &ch : s)
    {
        if (ch == '?' or cnt[ch - 'a'])
            m[ch]++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (!m.contains(int(i + 'a')) and cnt[i])
            m[i + 'a'] = 0;
    }

    std::vector<std::pair<int, char>> a;
    for (auto [ch, f] : m)
    {
        if (ch != '?')
            a.emplace_back(f, ch);
    }

    int left = 1;
    int right = 1e6;

    std::string ans = s;
    auto good = [&](int mid)
    {
        int x = m['?'];
        std::deque<int> pos;
        for (int i = 0; i < std::size(s); i++)
        {
            if (s[i] == '?')
                pos.emplace_back(i);
        }

        std::map<int, int> f;
        for (int i = 0; i < std::ssize(a); i++)
        {
            i64 need = 1LL * mid * cnt[a[i].second - 'a'] - a[i].first; 
            if (need <= 0)
                continue;

            if (need > x)
                return false;

            f[a[i].second] = need;
            x -= need;
        }

        ans = s;
        for (auto [ch, freq] : f)
        {
            while (freq--)
            {
                ans[pos.front()] = ch;
                pos.pop_front();
            }
        }

        for (auto &ch : ans)
        {
            if (ch == '?')
                ch = 'z';
        }

        return true;
    };

    while (left <= right)
    {
        int mid = std::midpoint(left, right);

        if (good(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    for (auto &ch : ans)
    {
        if (ch == '?')
            ch = 'a';
    }

    std::cout << ans;

    return 0;
}