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

    std::map<int, int> power;
    auto primeFactor = [&](int x)
    {
        std::map<int, int> m;
        for (int i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
                m[i]++, x /= i;
        }

        if (x > 1)
            m[x]++;
        return m;
    };

    power = primeFactor(a[0]);
    std::vector<std::array<int, 2>> powers;
    powers.push_back({power[2], power[3]});

    std::array<int, 2> min{power[2], power[3]};

    for (int i = 1; i < n; i++)
    {
        auto temp = primeFactor(a[i]);
        min[0] = std::min(min[0], temp[2]);
        min[1] = std::min(min[1], temp[3]);

        powers.push_back({temp[2], temp[3]});

        for (auto [num, alpha] : power)
        {
            if (num == 2 or num == 3)
                continue;

            if (alpha != temp[num])
            {
                std::cout << "-1\n";
                return 0;
            }
        }

        for (auto [num, alpha] : temp)
        {
            if (num == 2 or num == 3)
                continue;

            if (alpha != power[num])
            {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    i64 op = 0;

    for (int i = 0; i < std::size(powers); i++)
    {
        op += std::abs(powers[i][0] - min[0]);
        op += std::abs(powers[i][1] - min[1]);
    }

    std::cout << op << "\n";

    return 0;
}