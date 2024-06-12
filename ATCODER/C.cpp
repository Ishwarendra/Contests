#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, a, b;
    std::cin >> n >> a >> b;

    std::vector<i64> d(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> d[i];
        d[i]--;
        d[i] %= (a + b);
    }

    std::sort(std::begin(d), std::end(d));

    if (d.back() < a)
    {
        std::cout << "Yes";
        return 0;
    }

    d.emplace_back(d.front() + a + b);

    for (int i = 0; i <= n; i++)
    {
        if (d[i] - d[i - 1] > b)
        {
            std::cout << "Yes";
            return 0;
        }
    }

    std::cout << "No";
}
