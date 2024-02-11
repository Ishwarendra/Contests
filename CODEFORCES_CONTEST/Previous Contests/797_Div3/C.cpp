#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> s(n), f(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];

    for (int i = 0; i < n; ++i)
        std::cin >> f[i];

    std::vector<int> d(n);
    int st = 0;
    for (int i = 0; i < n; ++i)
    {
        st = std::max(s[i], st);
        d[i] = f[i] - st;
        st = f[i];
    }

    for (int x : d)
        std::cout << x << " ";
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}