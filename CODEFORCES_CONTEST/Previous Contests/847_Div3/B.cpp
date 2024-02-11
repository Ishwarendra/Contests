#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, s, r;
    std::cin >> n >> s >> r;

    int last = s - r;

    for (int i = n - 1; i >= 1; i--)  
    {
        for (int j = last; j >= 1; j--)
        {
            if ((r - j) >= i - 1)
            {
                std::cout << j << " ";
                r -= j;
                break;
            }
        }
    }

    std::cout << last << "\n";
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