#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    auto getBit = [&](i64 x, int pos) { return x >> pos & 1; };  
    int msb = std::__lg(n);

    auto good = [&]()
    {
        int fzero = -1, lone = -1;
        for (int i = 0; i < msb; i++)
        {
            if (getBit(n, i))
            {
                if (lone == -1)
                    lone = i;
            }
            else
                fzero = i;
        }

        if (fzero == -1 or lone == -1)
            return true;

        return fzero < lone;
    };

    i64 cost = 0;
    if (good())
        std::cout << "0\n";
    else
    {
        for (int i = 0; i < msb; i++)
        {
            if (good())
                break;

            if (getBit(n, i))
            {
                cost += 1 << i;
                n += 1 << i;
            }
        }

        std::cout << cost << "\n";
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