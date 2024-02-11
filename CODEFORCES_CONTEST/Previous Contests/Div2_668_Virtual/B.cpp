#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    i64 sum = 0, extra = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < 0)
            sum += a[i];
        else
        {
            if (sum + a[i] > 0)
                extra += (a[i] + sum), sum = 0;
            else
                sum += a[i];
        }
    }

    std::cout << (extra - sum) / 2 << "\n";
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