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
    i64 contrast = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i)
            contrast += std::abs(a[i] - a[i - 1]);
    }

    if (n == 1 || contrast == 0)
    {
        std::cout << 1 << "\n";
        return;
    }

    int ans = 0;
    for (int i = 1; i < n;)
    {
        std::array<std::function<bool(int, int)>, 2> cmp {std::less_equal<int>(), std::greater_equal<int>()};
        int id = 0;
        int j = i;
        while (j < n and a[j] == a[j - 1])
            j++;

        if (j < n and a[j] >= a[j - 1])
            id = 1;

        j = i;
        while (j < n and cmp[id](a[j], a[j - 1]))
            j++;
        ans += j - i - 1;
        i = j;
    }

    std::cout << n - ans << "\n";
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