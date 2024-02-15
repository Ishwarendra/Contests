#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
    	int e;
    	std::cin >> e;
    	a.emplace_back(e % x, e % y);
    }

    i64 ans = 0;
    std::map<std::pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
    	int a1 = (x - a[i].first) % x;
    	int a2 = a[i].second;
    	ans += m[{a1, a2}];

    	m[a[i]]++;
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