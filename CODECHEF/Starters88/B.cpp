#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    auto getBit = [&](int x, int pos) { return (x >> pos) & 1; };
    int x = 0;
    int extra = 0;
    for (int i = 0; i < c; i++)  
    {
        if (!getBit(a, i) and !getBit(b, i))
            x |= (1 << i);
        else if (getBit(a, i) != getBit(b, i))
            extra++;
    }

    std::cout << (1 << extra) << "\n";
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