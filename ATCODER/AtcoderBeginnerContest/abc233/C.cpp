#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, x;
    std::cin >> n >> x;

    std::vector<std::vector<long long>> a(n);

    for (int i = 0; i < n; ++i)    
    {
        int l; 
        std::cin >> l;
        a[i].resize(l);

        for (int j = 0; j < l; ++j)
            std::cin >> a[i][j];
    }

    long long prod = 1, cnt = 0;
    std::function<void(int)> f;

    f = [&](int i)
    {
        if (i == n or prod > x)
        {
            if (prod == x)
                cnt++;
            return;
        }

        for (int j = 0; j < (int)a[i].size(); j++)
        {
            long long y = (x + prod - 1) / prod;

            if (a[i][j] > y)
                continue;

            prod *= a[i][j];
            f(i + 1);
            prod /= a[i][j];
        }
    };
    
    f(0);

    std::cout << cnt; 

    return 0;
}