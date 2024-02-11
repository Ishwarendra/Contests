#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto size(int x) { return std::ssize(std::to_string(x)); }

void solve()
{
    int n;
    int x;
    std::cin >> x >> n;  

    std::array<int, 2> ans{1000, 1000};
    for (int i = 8; i < 10000; i += 8)
    {
        if (size(n) == size(i))
        {
            auto s = std::to_string(n);
            auto t = std::to_string(i);

            int cnt = 0;
            for (int i = 0; i < std::size(s); i++)
                cnt += s[i] != t[i];

            ans = std::min(ans, std::array{cnt, i});
        }
    }

    std::cout << ans[0] << "\n";
    // std::cout << ans[1] << "\n";
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