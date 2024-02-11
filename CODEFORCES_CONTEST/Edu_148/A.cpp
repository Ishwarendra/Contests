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
    int d = std::size(std::set(std::begin(s), std::end(s)));

    if (d == 1)
        std::cout << "NO\n";
    else
    {
        int cnt = std::count(std::begin(s), std::end(s), s[n / 2]);
        if (cnt == 1 and n % 2 == 1 and d == 2)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
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