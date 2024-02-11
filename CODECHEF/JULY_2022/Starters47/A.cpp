#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i)
        std::cin >> p[i];

    int one = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == 1)
            one = i;
    }

    int ans = 0;

    for (int i = one; i > 0; i--)
    {
        std::swap(p[i], p[i - 1]);
        ans++;
    }

    for (int i = 0; i < n; i++)
    {
        if (p[i] == n)
            last = i;
    }

    for (int i = last; i < n - 1; i++)
    {
        std::swap(p[i], p[i + 1]);
        ans++;
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