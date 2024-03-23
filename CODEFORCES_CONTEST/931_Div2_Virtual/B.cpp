#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    auto get = [&](int x)
    {
        int ans = x;
        for (int one = 0; one <= 30; one++)
        {
            for (int three = 0; three <= 10; three++)
            {
                for (int six = 0; six <= 6; six++)
                {
                    for (int ten = 0; ten <= 4; ten++)
                    {
                        int made = one + three * 3 + six * 6 + ten * 10;
                        
                        if (made <= x and (x - made) % 15 == 0)
                            ans = std::min(ans, one + three + six + ten + (x - made) / 15);
                    }
                }
            }
        }

        return ans;
    };

    std::cout << get(n) << '\n';
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