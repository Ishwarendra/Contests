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

    std::array<int, 2> alice {1, 0}, bob {0, 0};
    int turn = 0, black = 1;
    n--;

    int add = 2;
    for (int i = 0; i < n;)
    {
        int count = 0;
        while (i < n and count < add + add + 1)
        {
            (turn ? alice[black] : bob[black])++;
            black ^= 1;
            i++;
            count++;
        }

        add += 2;
        turn ^= 1;
    }

    std::cout << alice[0] << " " << alice[1] << " " << bob[0] << " " << bob[1] << '\n';
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