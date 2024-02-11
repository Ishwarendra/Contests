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

    k %= (n + 1);
    std::vector<int> vis(n + 1), a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        vis[a[i]]++;
    }

    std::vector<int> missing;
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
            missing.emplace_back(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        vis[missing.back()] = 1;
        vis[a[i]] = 0;
        missing.emplace_back(a[i]);
    }

    int sz = n + 1;
    int st = k - 1;
    if (st < 0)
        st += sz;

    auto sub = [&](int a, int b)
    {
        int ans = a - b;
        if (ans < 0)
            ans += sz;
        return ans;
    };

    for (int i = st, cnt = 0; cnt < n; i = sub(i, 1), cnt++)
        std::cout << missing[i] << " \n"[cnt == n - 1];
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