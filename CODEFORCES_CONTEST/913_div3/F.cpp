#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (std::is_sorted(std::begin(a), std::end(a)))
    {
        std::cout << "0\n";
        return;
    }

    int min_id = -1, update = 1;
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[(i + 1) % n])
        {
            if (min_id != -1)
            {
                update = 0;
                break;
            }

            min_id = i;
        }
    }

    if (update)
        ans = std::min({ans, n - min_id, min_id + 2});

    if (std::is_sorted(std::begin(a), std::end(a), std::greater()))
        ans = std::min(ans, 1);

    int max_id = -1;
    update = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[(i + 1) % n])
        {
            if (max_id != -1)
            {
                update = 0;
                break;
            }

            max_id = i;
        }
    }
    // print(min_id, max_id)
    if (update)
        ans = std::min({ans, n - max_id - 1, max_id + 3});

    std::cout << (ans == inf ? -1 : ans) << "\n";
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