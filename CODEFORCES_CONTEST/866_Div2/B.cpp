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

    if (!std::count(std::begin(s), std::end(s), '0'))
    {
        std::cout << 1LL * n * n << "\n";
        return;
    }

    s += s;

    int max = 0, cur = 0;
    for (auto ch : s)  
    {
        if (ch == '0')
        {
            max = std::max(max, cur);
            cur = 0;
        }
        else
            cur++;
    }

    if (max % 2)
        std::cout << 1LL * (max / 2 + 1) * (max / 2 + 1) << "\n";
    else
        std::cout << 1LL * (max / 2 + 1) * (max / 2) << "\n";
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