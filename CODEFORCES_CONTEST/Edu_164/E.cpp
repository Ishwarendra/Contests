#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
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

    std::vector<i64> b;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        if (i > 0)
            x = a[i] - a[i - 1];
        else
            x = a[i] - 0;

        if (x > 0)
            b.emplace_back(x);
    }

    const int N = *std::max_element(std::begin(a), std::end(a));
    std::vector<i64> ans(N + 1);
    for (int i = 1; i <= N; i++)
    {

    }

    return 0;
}