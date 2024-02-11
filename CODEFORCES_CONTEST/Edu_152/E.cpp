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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::pair<int, int>> min(n), max(n);
    i64 ans = 0;
    auto f = [&](auto self, int l, int r)
    {
        if (l >= r)
            return;

        int m = (l + r) / 2;
        self(self, l, m);
        self(self, m + 1, r);

        min[m] = {a[m], m}, max[m] = {a[m], m};
        for (int i = m - 1; i >= l; i--)
        {
            min[i] = std::min(min[i + 1], std::pair{a[i], i});
            max[i] = std::max(max[i + 1], std::pair{a[i], i});
        }

        min[m + 1] = max[m + 1] = {a[m + 1], m + 1};
        for (int i = m + 2; i <= r; i++)
        {
            min[i] = std::min(min[i - 1], std::pair{a[i], i});
            max[i] = std::max(max[i - 1], std::pair{a[i], i});
        }

        // print(min, max, l, m, r)
        // small left, large right
        for (int i = m + 1, L = m, R = m; i <= r; i++)
        {
            while (L >= l and min[L].first > min[i].first)
                L--;
            while (R >= l and max[R].first < max[i].first)
                R--;

            ans += std::max(0, L - R);
        }

        // small left, large left
        for (int i = m, R = m + 1; i >= l; i--)
        {
            while (R <= r and max[R].first < max[i].first and min[R].first > min[i].first)
                R++;

            if (max[i].second > min[i].second)
                ans += R - m - 1;
        }

        // small right, large right
        for (int i = m + 1, L = m; i <= r; i++)
        {
            while (L >= l and min[L].first > min[i].first and max[L].first < max[i].first)
                L--;

            if (max[i].second > min[i].second)
                ans += m - L;
        }

    }; f(f, 0, n - 1);
    
    std::cout << ans;
    
    return 0;
}