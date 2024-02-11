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

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> b[i];

    std::vector<int> a(1, b[0]);
    for (int i = 1; i < n; i++)
    {
        if (b[i] < b[i - 1])
            a.emplace_back(b[i]);
        a.emplace_back(b[i]);
    }

    std::cout << std::size(a) << "\n";
    for (int i = 0; i < std::size(a); i++)
        std::cout << a[i] << " \n"[i + 1 == std::size(a)];
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