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

    for (int i = 0; i < n; ++i)  
    {
        int x;
        std::cin >> x;
    }

    auto one = [&](int i)
    {
        std::cout << "1 " << i << " " << i + 1 << "\n";
    };

    auto two = [&](int i)
    {
        std::cout << "2 " << i << " " << i + 1 << "\n";
    }; 

    std::cout << 3 * n << "\n";
    for (int i = 1; i <= n; i += 2)
    {
        one(i);
        two(i);
        one(i); one(i);
        two(i);
        one(i);
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