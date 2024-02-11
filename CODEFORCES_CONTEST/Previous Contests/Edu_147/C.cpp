#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    auto get = [&](char ch)  
    {
        std::vector<int> pos;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ch)
                pos.emplace_back(i);
        }

        if (pos.empty())
            return 0;

        int cnt = 1;
        std::vector<int> a;
        for (int i = 1; i < std::size(pos); i++)
        {
            if (pos[i - 1] + 1 == pos[i])
                cnt++;
            else
                a.emplace_back(cnt), cnt = 1;
        }

        if (cnt > 0)
            a.emplace_back(cnt);
        int ans = 0;

        for (int i = 0; i < std::size(a); i++)
        {
            cnt = 0;
            while (a[i] > 0)
                a[i] /= 2, cnt++;

            ans = std::max(ans, cnt);
        }

        return ans;
    };

    int ans = 1e9;
    for (char ch = 'a'; ch <= 'z'; ch++)
        ans = std::min(ans, get(ch));

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