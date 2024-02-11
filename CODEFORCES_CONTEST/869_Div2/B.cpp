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

    if (n == 1)
    {
        std::cout << "1\n";
        return;
    }

    i64 sum = 1LL * n * (n + 1) / 2;
    if (sum % n == 0)  
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> a(n);
    int even = 2, odd = 1;
    for (int i = 0; i < n; i += 2, even += 2, odd += 2)
        a[i] = even, a[i + 1] = odd;

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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