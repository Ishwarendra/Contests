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
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> vis(n, 1), p(n, -1);
    p.back() = n - a.back();
    vis[p.back()] = 0;

    int mex = p.back();

    for (int i = n - 2; i >= 0; i--)
    {
        p[i] = mex - a[i];
        vis[p[i]] = 0;
        mex = std::min(mex, p[i]);
    }

    for (int i = 0; i < n; i++)
        std::cout << p[i] << " \n"[i == n - 1];
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