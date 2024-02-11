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

    std::vector<int> pos(n), vis(n), a(n);
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a[i] = x - 1;
        pos[x - 1] = i;
    }

    int can = 1;
    int end = n;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;

        for (int j = pos[i]; j < end - 1; j++)
        {
            vis[a[j]] = 1;
            if (a[j + 1] != a[j] + 1)
                can = 0;
        }

        vis[a[end - 1]] = 1;
        end = pos[i];
    }

    std::cout << (can ? "Yes\n" : "No\n");
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