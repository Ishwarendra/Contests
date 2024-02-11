#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k, g, m;
    std::cin >> k >> g >> m;

    int glass = 0, mug = 0;
    while (k--)
    {
        if (glass == g)
            glass = 0;
        else if (mug == 0)
            mug = m;
        else
        {
            int transfer = std::min(g - glass, mug);
            mug -= transfer;
            glass += transfer;
        }
    }

    std::cout << glass << " " << mug << "\n";
    
    return 0;
}