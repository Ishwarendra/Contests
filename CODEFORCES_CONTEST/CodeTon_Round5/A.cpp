#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    int i, j;
    for (i = n - 1, j = m - 1; i >= 0 and j >= 0; )
    {
        if (a[i] > b[j])
            a[i] -= b[j], j--;
        else if (b[j] > a[i])
            b[j] -= a[i], i--;
        else
            i--, j--; 
    }

    if (i < 0 and j < 0)
        std::cout << "Draw\n";
    else if (i < 0)
        std::cout << "Tenzing\n";
    else
        std::cout << "Tsondu\n";
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