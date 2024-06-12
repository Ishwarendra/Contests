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
    std::string s;
    std::cin >> n >> s;

    auto get = [&](std::string t)
    {
        int cnt = 0, sz = std::size(t);
        for (int i = 0; i < n; i++)
            cnt += s[i] != t[i % sz];
        return cnt;
    };

    for (int len = 1; len < n; len++)
    {
        if (n % len)
            continue;

        int t = std::min(get(s.substr(0, len)), get(s.substr(len, len)));
        if (t <= 1)
        {
            std::cout << len << "\n";
            return;
        }
    }  

    std::cout << n << "\n";
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