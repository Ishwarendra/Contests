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
    std::string s, t;
    std::cin >> n >> s >> t;

    auto get = [&](int cnt)  
    {
        int ans = 0;
        if (cnt)
            std::reverse(std::begin(t), std::end(t));

        for (int i = 0; i < n; i++)
            ans += s[i] != t[i];

        if (cnt)
            std::reverse(std::begin(t), std::end(t));

        ans = ans * 2;
        if (ans == 0)
            ans = (cnt ? 2 : 0);
        else if (!cnt)
            ans -= (ans / 2) % 2;
        else
            ans -= (ans / 2) % 2 == 0;

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