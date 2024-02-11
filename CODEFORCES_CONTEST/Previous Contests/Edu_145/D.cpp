#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

const i64 base = 1e12;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    auto t = s;

    if (std::is_sorted(std::begin(s), std::end(s)))
    {
        std::cout << "0\n";
        return;
    }

    std::vector<int> pref(n), suff(n);
    pref[0] = s[0] == '1';
    suff.back() = s.back() == '0';

    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + (s[i] == '1');
    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + (s[i] == '0');
    
    i64 ans = std::min(suff[1] * (base + 1), pref[n - 2] * (base + 1));
    for (int i = 1; i < n - 1; i++)
    {
        int del = pref[i - 1] + suff[i + 1];
        ans = std::min(ans, del * (base + 1));
    }

    auto get = [&](int st, int end, char ch) -> i64
    {
        int del = 0;
        i64 add = 0;
        if (st == 2 and s[0] == '1' and s[1] == '0')
            add += base;
        if (st == 0 and s[n - 2] == '1' and s[n - 1] == '0')
            add += base;

        for (int i = st; i <= end; i++)
            del += s[i] == ch;

        return 1LL * del * (base + 1) + add;
    };

    ans = std::min({ans, get(2, n - 1, '0'), get(0, n - 3, '1')});
    for (int i = 1; i < n - 2; i++)
    {
        int del = pref[i - 1] + suff[i + 2];
        i64 add = (s[i] == '1' and s[i + 1] == '0' ? base : 0LL);
        ans = std::min(ans, del * (base + 1) + add);
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