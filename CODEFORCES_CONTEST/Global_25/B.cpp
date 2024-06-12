#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    k--;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> big;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[k])
            big.emplace_back(i);
    }

    if (big.empty())
    {
        std::cout << n - 1 << "\n";
        return;
    }

    int me = a[k];

    auto get = [&](int id)
    {
        std::swap(a[id], a[k]);
        int opponent = 0, win = 0;
        for (int i = 1; i < n; i++)
        {
            opponent = std::max({opponent, a[i - 1], a[i]});
            if (me == opponent)
                win++;
        }

        std::swap(a[id], a[k]);
        return win;
    };
    std::cout << std::max(get(0), get(big.front())) << "\n";
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