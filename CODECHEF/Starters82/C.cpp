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

    if (n == 4)
    {
        std::cout << "12 10 6 14\n3 8 4 1\n5 15 11 9\n2 7 13 16\n";
        return;
    }

    std::vector a(n, std::vector<int>(n));
    int start = n * n;

    for (int _ = 0; _ < n; _++)
    {
        int i = 0, j = _;
        while (i != j)
        {
            a[i][j] = start;
            start -= 2;
            if (start <= 0)
                start = n * n - 1;
            i++;
        }

        while (j >= 0)
        {
            a[i][j] = start;
            start -= 2;
            if (start <= 0)
                start = n * n - 1;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
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