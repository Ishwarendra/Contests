#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int turn = 1;
    turn -= c % 2 == 0;

    a += turn;
    std::cout << (a > b ? "First\n" : "Second\n");    
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