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
    std::string s;
    std::cin >> n >> s;

    int rem = 0;
    for (auto ch : s)  
        rem = (rem * 10 + ch - '0') % 8;

    if (rem == 0)
        std::cout << s << "\n";
    else
    {
        int x = s[n - 1] - '0' + 8 - rem;
        x %= 8;
        if (x == 0)
            x = 8;
        s[n - 1] = x + '0';
        std::cout << s << "\n";
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