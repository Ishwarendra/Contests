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

    std::vector<int> a(n);
    i64 how_many = 0;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        how_many += __builtin_ctz(a[i]);
    }

    std::vector<int> can;
    int pos = 0;
    for (int i = 1; i <= n; i++)
        can.push_back(__builtin_ctz(i));

    std::sort(std::begin(can), std::end(can), std::greater());

    if (how_many + std::accumulate(std::begin(can), std::end(can), 0LL) < n)
        std::cout << "-1\n";
    else
    {
        int ans = 0;
        while (pos < std::ssize(can) and how_many < n)
        {
            how_many += can[pos++];
            ans++;
        }

        std::cout << ans << "\n";
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