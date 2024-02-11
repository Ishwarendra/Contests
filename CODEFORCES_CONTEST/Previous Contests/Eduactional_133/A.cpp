#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n == 1)
        std::cout << "2\n";
    else if (n % 3 == 0)
        std::cout << n / 3 << "\n";
    else if (n % 3 == 2)
        std::cout << (n - 2) / 3 + 1 << "\n";
    else
        std::cout << (n - 4) / 3 + 2 << "\n";
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