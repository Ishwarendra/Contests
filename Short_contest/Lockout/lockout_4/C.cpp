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
    int max = 0, sec_max = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] >= max)
            sec_max = max, max = a[i];
        else if (a[i] > sec_max)
            sec_max = a[i];
    }

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    std::vector<int> del;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != max and sum - max - a[i] == max)
            del.emplace_back(i + 1);
        else if (a[i] == max and sum - sec_max - a[i] == sec_max)
            del.emplace_back(i + 1);
    }

    std::cout << std::size(del) << "\n";
    for (int i = 0; i < std::size(del); i++)
        std::cout << del[i] << " \n"[i == std::ssize(del) - 1];

    return 0;
}