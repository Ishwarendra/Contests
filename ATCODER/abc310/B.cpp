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

    std::vector<int> p(n);
    std::vector has(n, std::bitset<101>());
    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> p[i] >> len;

        for (int j = 0; j < len; j++)
        {
            int f;
            std::cin >> f;
            has[i][f - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i] < p[j])
                continue;

            int extra = 0;
            int ok = 1;

            for (int k = 0; k < m; k++)    
            {
                if (has[i][k] and !has[j][k])
                    ok = 0;
                else if (!has[i][k] and has[j][k])
                    extra++;
            }

            ok &= (extra > 0 || p[i] > p[j]);

            if (ok)
            {
                std::cout << "Yes";
                return 0;
            }
        }
    }
    
    std::cout << "No";
    return 0;
}