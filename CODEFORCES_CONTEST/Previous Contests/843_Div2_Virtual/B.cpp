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

    std::vector<int> adj[n];
    std::map<int, int> cnt;

    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;

        for (int j = 0; j < k; j++)
        {
            int x;
            std::cin >> x;
            adj[i].emplace_back(x);
            cnt[x]++;
        }
    }

    int can = 0;
    for (int i = 0; i < n; i++)
    {
        int yes = 1;
        for (int bit : adj[i])
            yes &= (cnt[bit] > 1);

        can |= yes;
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