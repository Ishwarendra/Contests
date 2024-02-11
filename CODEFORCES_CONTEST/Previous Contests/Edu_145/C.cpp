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

    std::vector<int> a(n, -1e3);

    int c = 0;
    std::vector<int> sum;
    for (int i = 1; i <= n + 1; i++)
    {
        sum.emplace_back(c);
        c += i;
    }

    int id = std::upper_bound(std::begin(sum), std::end(sum), k) - std::begin(sum) - 1;
    int pos = 0;
    for (int num = 2; pos < id; pos++)
        a[pos] = num++;

    int rem = k - sum[id];
    rem--;

    if (rem != -1)
    {
        int s = 0;
        for (int i = rem; i < pos; i++)
            s += a[i];

        a[pos] = 1 - s;
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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