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
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    auto getBit = [&](i64 x, int pos) { return x >> pos & 1LL; };

    int max = 0;
    for (int pos = 0; pos < 64; pos++)
    {
        if (getBit(a.back(), pos))
            max = pos;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += getBit(a[i], max);

    std::cout << (cnt + 1) / 2 << "\n";
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