#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    auto par = [&](int x) { return (x & 1); };

    if (n % (k + 1) == k)   
        std::cout << "Shivansh\n";
    else
        std::cout << (par(n % (k + 1)) == 1 ? "Shivansh\n" : "Tina\n");
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