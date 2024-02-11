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

    std::vector<int> pos(n);  
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        pos[x - 1] = i;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (pos[i] < pos[i - 1])
            ans++;
    }

    std::cout << ans << "\n";
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