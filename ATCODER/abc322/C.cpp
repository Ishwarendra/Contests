#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        auto it = std::lower_bound(std::begin(a), std::end(a), i);
        std::cout << (*it - i) << "\n"; 
    }
    
    return 0;
}