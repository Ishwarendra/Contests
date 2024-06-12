#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> a(n);
    std::array<int, 2> max {0, -1};
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        std::array<int, 2> cur;
        cur[0] = std::count(std::begin(a[i]), std::end(a[i]), '#');
        cur[1] = i;
        max = std::max(max, cur);
    }
    
    int id = a[max[1]].find('#');
    int len = max[0];
    std::cout << max[1] + 1 << " " << id + len / 2 + 1 << "\n";
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