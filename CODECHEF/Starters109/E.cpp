#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(x...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9 + 1;

void solve()
{
    int n, d;
    std::cin >> n >> d;

    std::vector<int> pmax(n), pmin(n);
    for (int i = 0; i < n; i++)
        std::cin >> pmax[i];
    for (int i = 0; i < n; i++)
        std::cin >> pmin[i];

    for (int i = 1; i < n; i++)
    {
        if (pmax[i - 1] > pmax[i] or pmin[i - 1] < pmin[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::vector<int> a(n, inf);
    a[0] = pmax[0];
    int max = a[0], min = a[0];

    if (pmax[0] != pmin[0])
    {
        std::cout << "NO\n";
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (max != pmax[i] and min != pmin[i])
        {
            std::cout << "NO\n";
            return;
        }

        if (max != pmax[i])
            a[i] = pmax[i];
        if (min != pmin[i])
            a[i] = pmin[i];

        max = pmax[i], min = pmin[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] != inf)
            continue;

        int j = i;
        while (j < n and a[j] == inf)
            j++;

        if (j == n)
        {
            while (i < n)
                a[i] = a[i - 1], i++;
            break;
        }

        min = std::min(a[i - 1], a[j]);
        max = std::max(a[i - 1], a[j]);

        for (int k = i; k < j; k++)
        {
            if (pmax[j] != pmax[j - 1] and pmax[j] >= a[k - 1]
                or pmin[j] != pmin[j - 1] and pmin[j] >= a[k - 1])
                a[k] = std::min(pmax[k], std::max(pmin[j], a[k - 1] + d));                
            else
                a[k] = std::max(pmin[k], std::min(pmax[j], a[k - 1] - d));
        }

        i = j;
    }

    max = min = a[0];
    for (int i = 1; i < n; i++)
    {
        max = std::max(max, a[i]);
        min = std::min(min, a[i]);
        assert(a[i] != inf);

        if (pmax[i] != max or pmin[i] != min or a[i] == inf)
        {
            std::cout << "NO\n";
            return;
        }

        if (std::abs(a[i] - a[i - 1]) > d)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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