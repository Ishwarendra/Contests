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

    std::vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        if (a)
            pos.emplace_back(i);
    }

    int sz = std::size(pos);
    std::cout << (pos.back() - pos.front() + 1) - sz << "\n";
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