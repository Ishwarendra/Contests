#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
void solve()
{
    int n, m;
    std::cin >> m;

    n = 2;

    std::vector a(n, std::vector<int>(m));  
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> a[i][j];

    
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