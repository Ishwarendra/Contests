#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::cout << n << "\n";
    std::vector<int> a(n);
    std::iota(std::begin(a), std::end(a), 1);

    for (int i : a)  
        std::cout << i << " ";
    std::cout << "\n";

    for (int i = 0; i < n - 1; i++)
    {
        std::swap(a[i], a[i + 1]);
        for (int i : a)
            std::cout << i << " ";
        std::cout << "\n";
    }
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