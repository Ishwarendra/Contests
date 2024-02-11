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

    int one = 0, minus = 0;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        one += x == 1;
        minus += x == -1;
    }

    if (one - minus >= 0 and minus % 2 == 0)
        std::cout << "0\n";
    else if (one - minus >= 0)
        std::cout << "1\n";
    else
    {
        int need = (minus - one + 1) / 2;
        if ((minus - need) % 2)
            std::cout << need + 1 << "\n";
        else
            std::cout << need << "\n";
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