#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> get(int n)
{
    if (n == 4)
        return {3, 4, 1, 2};
    if (n == 5)
        return {4, 5, 1, 2, 3};
    if (n == 6)
        return {4, 5, 6, 1, 2, 3};

    return {3, 5, 1, 6, 7, 4, 2};
}

void solve()
{
    int n;
    std::cin >> n;

    if (n <= 3)  
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> a(n);
    while (n > 7)
    {
        a[n - 1] = n - 2, a[n - 2] = n - 3;
        a[n - 3] = n, a[n - 4] = n - 1;
        n -= 4;
    }

    for (int i = 0; const auto x : get(n))
        a[i++] = x;

    n = std::size(a);
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