#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

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
    
    int q;
    std::cin >> q;

    ordered_set<std::pair<int, int>> pbds;
    int L = 0, R = 0;
    std::map<int, int> m;

    while (q--)
    {
        char t;
        int id;
        std::cin >> t >> id;

        if (t == 'L')
        {
            pbds.insert({--L, id});
            m[id] = L;
        }
        else if (t == 'R')
        {
            pbds.insert({++R, id});
            m[id] = R;
        }
        else
        {
            auto k = pbds.order_of_key({m[id], id});
            int sz = std::size(pbds);

            std::cout << std::min(k, sz - k - 1) << "\n";
        }
    }
    
    return 0;
}