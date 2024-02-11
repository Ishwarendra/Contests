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
    int n, k;
    std::cin >> n >> k;

    int min = 1, max = n;
    std::vector<int> a(n);
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j += k)
            a[j] = (i % 2 ? min++ : max--);
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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