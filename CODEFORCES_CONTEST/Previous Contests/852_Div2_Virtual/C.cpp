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

    int max = n, min = 1;
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (std::min(a[i], a[j]) != min and std::max(a[i], a[j]) != max)
        {
            std::cout << i + 1 << " " << j + 1 << "\n";
            return;
        }
        if (i < n and a[i] == min) min++, i++;
        if (j >= 0 and a[j] == min) min++, j--;

        if (i < n and a[i] == max) max--, i++;
        if (j >= 0 and a[j] == max) max--, j--;
    }

    std::cout << "-1\n";
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