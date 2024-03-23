#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, m;
    std::cin >> n >> m;

    if ((n ^ m) < n)  
    {
        std::cout << 1 << "\n" << n << " " << m << "\n";
        return;
    }

    auto getBit = [&](i64 x, int pos) { return x >> pos & 1LL; };

    int msb = std::__lg(n);
    int one = msb, two = -1;

    for (int i = msb - 1; i >= 0; i--)
    {
        if (getBit(n, i))
        {
            two = i;
            break;
        }
    }

    if (two == -1 || (two < std::__lg(m) and std::__lg(m) < one))
    {
        std::cout << "-1\n";
        return;
    }

    std::cout << 2 << "\n" << n << " " << (m | (1LL << two)) << " " << m << "\n";
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