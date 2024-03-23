#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>;

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

    std::vector<int> a(n), ord(n);
    ordered_set<std::pair<int, int>, std::greater<>> pbds;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pbds.insert({a[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> ord[i];
        ord[i]--;
    }

    int max = *std::max_element(std::begin(a), std::end(a));
    std::array<i64, 2> ans{ max, -1 };

    i64 cnt = 1;
    for (int i = 0; i + 2 < std::size(pbds); i++)
    {
        cnt++;
        int id = ord[i];
        pbds.erase({a[id], id});

        max = pbds.find_by_order(i + 1)->first;
        ans = std::max(ans, std::array { 1LL * cnt * max, -cnt });
    }

    std::cout << ans[0] << " " << -ans[1] << "\n";
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