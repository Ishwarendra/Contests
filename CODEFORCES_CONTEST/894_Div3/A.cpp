#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::string t = "vika";
    int pos = 0;
    for (int col = 0; col < m and pos < 4; col++)
    {
        for (int row = 0; row < n; row++)
        {
            if (a[row][col] == t[pos])
            {
                pos++;
                break;
            }
        }
    }

    std::cout << (pos < 4 ? "NO\n" : "YES\n");
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