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
    int x;
    if (n >= 2)
        x = std::stoi(s.substr(n - 2));
    else
        x = std::stoi(s);

    int tens = x / 10;
    int ans = 0;
    if (tens % 2)
        ans = x % 20;
    else
        ans = x % 10;

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