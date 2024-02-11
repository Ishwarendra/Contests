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

    std::array<i64, 2> a{};
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a[i % 2] += x;
    }

    if (n == 1)
    {
        std::cout << (a[0] > 1 ? "Alice\n" : "Bob\n");
        return;
    }

    i64 s = a[0] + a[1];
    int rem = 2;

    if (a[0] % 2 or a[1] % 2)
        rem = 0;

    if (s % 4 == rem)
        std::cout << "Alice\n";
    else
        std::cout << "Bob\n";
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