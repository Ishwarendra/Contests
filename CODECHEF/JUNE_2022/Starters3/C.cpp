#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 a, b, c;
    std::cin >> a >> b >> c;

    auto getBit = [&](i64 x, int pos)
    {
        return (x >> pos) & 1LL;
    };

    for (int i = 0; i < 63; i++)
    {
        int setCnt = getBit(a, i) + getBit(b, i) + getBit(c, i);
        int unsetCnt = 3 - setCnt;

        if (setCnt == 3 or unsetCnt == 3)
            break;

        if (setCnt == 1)
        {
            if (getBit(a, i))
                a += (1LL << i);
            else if (getBit(b, i))
                b += (1LL << i);
            else
                c += (1LL << i);
        }
        else if (unsetCnt == 1)
        {
            if (!getBit(a, i))
                a += (1LL << i);
            else if (!getBit(b, i))
                b += (1LL << i);
            else
                c += (1LL << i);
        }

        if (a == b and b == c)
        {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << (a == b && b == c ?  "YES\n" : "NO\n");
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