#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    char ch;
    int x;
    std::cin >> ch >> x;

    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i == x - 1)
            continue;
        std::cout << ch << i + 1 << "\n";
    }
    for (char c = 'a'; c <= 'h'; c++)
    {
        if (c == ch)
            continue;
        std::cout << c << x << "\n";
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