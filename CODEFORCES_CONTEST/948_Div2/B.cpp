#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x;
    std::cin >> x;
    
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    std::vector<int> a(32);
    
    for (int i = 0; i < 30; i++)
    {
        if (getBit(x, i))
        {
            if (a[i])
                a[i + 1] = 1, a[i] = 0;
            else
            {
                if (a[i - 1] == 1)
                    a[i - 1] = -1, a[i + 1] = 1, a[i] = 0;
                else
                    a[i] = 1;
            }
        }
    }
    
    i64 s = 0;
    for (int i = 0; i < 32; i++)
        s += a[i] * (1LL << i);
    
    assert(s == x);
    std::cout << 32 << "\n";
    for (int i = 0; i < 32; i++)
        std::cout << a[i] << " \n"[i == 31];
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