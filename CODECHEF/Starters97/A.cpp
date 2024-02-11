#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    int zero = k + (k - 1) / 2;

    int sum = (n / (zero + 2)) * 3;
    
    n -= (n / (zero + 2)) * (zero + 2);
    if (n > 0)
        sum++;
    if (n > k + 1)
        sum += 2;

    std::cout << sum << "\n";
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