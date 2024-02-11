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
    
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
        if (m.count(a[i] - x) or m.count(a[i] + x))
        {
            std::cout << "Yes\n";
            return 0;
        }
    }

    std::cout << "No\n";
    
    return 0;
}