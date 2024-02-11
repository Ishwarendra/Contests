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
    
    int q;
    std::cin >> q;

    std::array<int, 31> a{};
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int x;
            std::cin >> x;
            a[x]++;
        }
        else
        {
            int x;
            std::cin >> x;

            auto b = a;
            std::string ans = "YES";
            for (int i = 0; i < 30; i++)
            {
                if (getBit(x, i))
                {
                    if (b[i] == 0)
                        ans = "NO";
                    else
                        b[i + 1] += (b[i] - 1) / 2, b[i] = 0;
                }
                else
                    b[i + 1] += b[i] / 2, b[i] &= 1;
            }

            std::cout << ans << "\n";
        }
    }
    
    return 0;
}