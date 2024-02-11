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

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x == 0)
            cnt++;
        else
            ans = std::max(ans, cnt), cnt = 0;
    }

    std::cout << std::max(ans, cnt) << "\n";
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