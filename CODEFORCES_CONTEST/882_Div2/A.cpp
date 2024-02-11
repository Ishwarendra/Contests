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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::multiset<int, std::greater<>> max;
    for (int i = 1; i < n; i++)
        max.emplace(std::abs(a[i] - a[i - 1]));

    k--;
    while (k-- and !max.empty())
        max.erase(std::begin(max));

    i64 sum = 0;
    for (auto x : max)
        sum += x;

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