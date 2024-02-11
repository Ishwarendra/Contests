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

    std::vector<i64> sum(n);
    for (int i = 0; i < n; i++) 
        std::cin >> sum[i];

    std::sort(std::begin(sum), std::end(sum), std::greater());
    for (int i = 1; i < n; i++)
        sum[i] += sum[i - 1];

    std::reverse(std::begin(sum), std::end(sum));
    for (int i = 0; i < n; i++)
        std::cout << sum[i] << " \n"[i == n - 1];
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