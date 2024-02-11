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

    int min = n - 1, max = 0;
    for (int i = 0; i < n; i++)  
    {
        char ch;
        std::cin >> ch;

        if (ch == 'B')
        {
            min = std::min(min, i);
            max = std::max(max, i);
        }
    }

    std::cout << std::max(0, max - min + 1) << "\n";
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