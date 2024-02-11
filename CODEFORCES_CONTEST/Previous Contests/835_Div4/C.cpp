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

    auto b = a;
    std::sort(std::begin(b), std::end(b));

    int max = b[std::ssize(b) - 1];
    int sec_max = b[std::ssize(b) - 2];

    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
            std::cout << a[i] - sec_max << " \n"[i == n - 1];
        else
            std::cout << a[i] - max << " \n"[i == n - 1];
    }
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