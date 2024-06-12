#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++)
    {  
        std::cin >> a[i];
        pos[a[i] >> 2].emplace_back(i);
    }

    std::vector<int> ans(n);
    for (auto &[num, p] : pos)
    {
        std::vector<int> b;
        for (auto id : p)
            b.emplace_back(a[id]);
        std::sort(std::begin(b), std::end(b));

        for (int j = 0; int id : p)
            ans[id] = b[j++];
    }
    
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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