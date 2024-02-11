#include "bits/stdc++.h"

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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)    
        std::cin >> a[i];

    int offset = 0, last_id = n - 1;
    auto add = [&](int x, int y) { return (x + y) % n; };
    auto sub = [&](int x, int y)  { return ((x - y) % n + n) % n; };

    for (int _ = 0; _ < std::min(n, k); _++)
    {
        int last_elem = a[last_id];
        if (last_elem > n)
        {
            std::cout << "No\n";
            return;
        }

        offset = add(offset, last_elem);
        last_id = sub(n - 1, offset);
    }

    std::cout << "Yes\n";
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