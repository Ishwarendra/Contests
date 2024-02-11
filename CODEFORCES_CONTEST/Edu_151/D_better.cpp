#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
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

    i64 psum = 0, maxDrop = 0, pmax = 0;
    i64 k = 0;
    for (int i = 0; i < n; i++)
    {
        psum += a[i];
        pmax = std::max(pmax, psum);
        i64 curDrop = pmax - psum;

        if (curDrop > maxDrop)
        {
            maxDrop = curDrop;
            k = pmax;
        }
    }

    print(maxDrop)
    std::cout << k << "\n";
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