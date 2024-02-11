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

    std::sort(std::begin(a), std::end(a));
    int p = 0, ans = a[0] != 0;
    
    for (int i = 0; i < n; i++)
    {
        if (p >= a[i] and (i + 1 >= n or p + 1 < a[i + 1]))
            ans++;

        p++;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}