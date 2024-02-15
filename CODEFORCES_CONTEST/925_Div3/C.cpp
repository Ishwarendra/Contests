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

    int i = 0, j = n - 1;
    while (i < n and a[0] == a[i])
    	i++;

    while (j >= 0 and a[n - 1] == a[j])
    	j--;

    int cost = n;
    if (a[0] == a[n - 1])
    	cost = std::max(0, j - i + 1);
    else
    	cost = std::min(n - i, j + 1);

    std::cout << cost << "\n"; 
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