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
    
    int n;
    std::cin >> n;

    std::vector<i64> x(n), l(n);
    for (int i = 0; i < n; i++)
        std::cin >> x[i];

    for (int i = 0; i < n; i++)
        std::cin >> l[i];

    std::vector<i64> options;
    for (int i = 0; i < n; i++)
    {
        options.emplace_back(x[i]);
        for (int j = 0; j < n; j++)
        {
            options.emplace_back(x[i] - l[j]);
            options.emplace_back(x[i] + l[j] + 1);            
        }
    }

    i64 ans = 0;
    auto valid = [&](i64 start)
    {
        std::vector<i64> a(n);
        for (int i = 0; i < n; i++)
            a[i] = std::abs(start - x[i]);

        std::sort(std::begin(a), std::end(a));
        for (int i = 0; i < n; i++)
        {
            if (l[i] < a[i])
                return false;
        }

        return true;
    };

    std::sort(std::begin(options), std::end(options));
    options.erase(std::unique(std::begin(options), std::end(options)), std::end(options));

    for (int i = 0; i + 1 < std::size(options); i++)
    {
        if (valid(options[i]))
            ans += options[i + 1] - options[i];
    }

    std::cout << ans;
    
    return 0;
}