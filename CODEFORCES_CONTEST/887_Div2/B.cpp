#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<i64> fib(30);

void solve()
{
    int n, k;
    std::cin >> n >> k;

    if (k >= 30)
    {
        if (n == 0)
            std::cout << "1\n";
        else
            std::cout << "0\n";

        return;
    }

    int ans = 0;
    for (int a = 0; a <= n; a++)
    {
        if (fib[k - 3] * a > n)
            continue;

        i64 cur = n - fib[k - 3] * a;
        if (cur < 0)
            break;

        if (cur % fib[k - 2] or cur / fib[k - 2] < a)
            continue;
        
        ans++;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i < 30; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    while (t--)
        solve();
    
    return 0;
}