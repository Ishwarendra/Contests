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

    int prod = 1;
    for (int i = 0; i < n; i++)  
    {
        int a;
        std::cin >> a;

        if (a < 0)
            prod *= -1;
        else if (a == 0)
            prod = 0;
    }

    if (prod <= 0)
        std::cout << "0\n";
    else
        std::cout << "1\n1 0\n";
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