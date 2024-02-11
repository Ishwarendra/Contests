#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, r, c;
    std::cin >> n >> k >> r >> c;

    r--, c--;
    std::vector<std::string> a(n, std::string(n, '.'));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < n; j++)
        {
            if ((c - r + 3 * n) % k == (j - i + 3 * n) % k)
                a[i][j] = 'X';
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\n";
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