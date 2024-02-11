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

    int ok = 1;
    std::vector<int> a(8);
    for (int i = 0; i < 8; i++)
    {
        std::cin >> a[i];
        if (i and a[i] < a[i - 1])
            ok = 0;
        if (a[i] % 25)
            ok = 0;
        if (a[i] < 100 or a[i] > 675)
            ok = 0;
    }

    std::cout << (ok ? "Yes" : "No");

    return 0;
}