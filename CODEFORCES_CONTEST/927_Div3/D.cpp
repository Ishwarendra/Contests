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
    char ch;
    std::cin >> n >> ch;

    std::map<char, std::vector<int>> m;
    for (int i = 0; i < 2 * n; i++)
    {
        char ch1, ch2;
        std::cin >> ch1 >> ch2;
        m[ch2].emplace_back(ch1 - '0');
    }

    int need = 0;
    for (auto &[_, p] : m)
    {
        std::sort(std::begin(p), std::end(p));
        if (_ == ch)
            continue;
        need += std::size(p) % 2;
    }

    if (std::size(m[ch]) < need)
        std::cout << "IMPOSSIBLE\n";
    else
    {
        for (auto &[ch_, p] : m)
        {
            if (ch_ == ch)
                continue;

            int sz = std::size(p);
            for (int i = 0; i + 1 < sz; i += 2)
                std::cout << p[i] << ch_ << " " << p[i + 1] << ch_ << "\n";

            if (sz % 2)
            {
                std::cout << p.back() << ch_ << " " << m[ch].back() << ch << "\n";
                m[ch].pop_back();
            }
        }

        auto &p = m[ch];
        for (int i = 0; i + 1 < std::size(p); i += 2)
            std::cout << p[i] << ch << " " << p[i + 1] << ch << "\n";
    }
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