#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 x;
    std::cin >> x;

    if (x == 1)
    {
        std::cout << "-1\n";
        return;
    }

    int N = 1e6;
    if (x - 1 <= 1e6)
    {
        std::cout << "1 1 " << (x - 1) << "\n";
        return;
    }

    i64 a = N;
    i64 b = x / N;
    i64 c = x - a * b;

    if (c == 0)
        b--, c += N;

    std::cout << a << " " << b << " " << c << "\n";
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