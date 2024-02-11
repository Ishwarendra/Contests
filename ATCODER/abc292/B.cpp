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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<int, int>> a(n);

    while (q--)
    {
        int t, x;
        std::cin >> t >> x;
        x--;

        if (t == 1)
            a[x].first++;
        else if (t == 2)
            a[x].second++;
        else
        {
            if (a[x].first >= 2 or a[x].second >= 1)
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
        }
    }
    
    return 0;
}