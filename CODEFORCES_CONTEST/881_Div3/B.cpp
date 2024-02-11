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
    i64 sum = 0;
    int cnt = 0, min = 0;

    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        sum += std::abs(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int j = i;
        if (a[i] >= 0)
            continue;

        while (j < n and a[j] <= 0)
            j++;

        i = j;
        min++;
    }

    std::cout << sum << " " << min << "\n";
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