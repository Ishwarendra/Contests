#include "bits/stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>; 

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
    
    int n, m, k;
    std::cin >> n >> m >> k;

    ordered_set<int, std::less_equal<int>> pbds;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
        pbds.insert(a[i]);

    i64 ans = 0;
    for (int i = 0; i < k; i++)
        ans += *pbds.find_by_order(i);

    auto erase = [&](int ele)
    {
        pbds.erase(pbds.find_by_order(pbds.order_of_key(ele)));
    };

    std::cout << ans << " ";

    for (int i = m; i < n; i++)
    {
        int biggest = *pbds.find_by_order(k - 1);
        erase(a[i - m]);

        if (a[i - m] <= biggest) // it was a part of ans
        {
            pbds.insert(a[i]);
            ans -= a[i - m];
            int num = *pbds.find_by_order(k - 1);
            
            ans += std::min(a[i], num);
        }
        else
        {
            int num = *pbds.find_by_order(k - 1);
            pbds.insert(a[i]);
            
            if (num > a[i])
                ans += a[i] - num;
        }
        std::cout << ans << " ";
        // print(pbds, a[i-m], a[i])
    }

    return 0;
}