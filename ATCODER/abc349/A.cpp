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

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        std::cin >> a;
        sum += a;
    }

    std::cout << (-sum);

    return 0;
}