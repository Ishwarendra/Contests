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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];

    if (n % 2 == 0)
    {
        std::cout << "2\n";
        std::cout << "1 " << n << "\n1 " << n << "\n";
    }
    else
    {
        std::cout << "4\n";
        std::cout << 1 << " " << n << "\n";
        std::cout << 1 << " " << n - 1 << "\n";
        std::cout << "2 " << n << "\n2 " << n << "\n";
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