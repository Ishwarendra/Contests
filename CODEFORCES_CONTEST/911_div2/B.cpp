#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int solve(int a, int b, int c)
{
    if ((b + c) % 2 == 0)
        return 1;
    return 0;
}

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << solve(a, b, c) << " " << solve(b, a, c) << " " << solve(c, a, b) << '\n';
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