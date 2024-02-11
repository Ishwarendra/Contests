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

void solve()
{
    int n;
    std::cin >> n;

    std::set<std::array<int, 3>> event;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        event.insert({a, 1, b});
        event.insert({b, -1, a});
    }

    ordered_set<int> st;
    i64 ans = 0;
    for (auto &[t, type, del] : event)
    {
        if (type == 1)
            st.insert(t);
        else
        {
            ans += st.order_of_key(del);
            st.erase(del);
        }
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