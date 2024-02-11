#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::vector<std::vector<int>> a(2, std::vector<int>(2));
    int cnt = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            std::cin >> a[i][j];
            cnt += a[i][j];
        }

    if (cnt == 0)
        std::cout << "0\n";
    else
        std::cout << (cnt == 4 ? 2 : 1) << "\n";
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