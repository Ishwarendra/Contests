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
    
    int q;
    std::cin >> q;

    std::vector<int> a;
    while (q--)
    {
        int t, x;
        std::cin >> t >> x;

        if (t == 1)
            a.emplace_back(x);
        else
            std::cout << a[std::ssize(a) - x] << "\n";
    }
    
    return 0;
}