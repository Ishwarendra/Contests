#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (a[i][j] == 'T' and a[i][j + 1] == 'T')
            {
                a[i][j] = 'P';
                a[i][j + 1] = 'C';
                j++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\n";
    
    return 0;
}