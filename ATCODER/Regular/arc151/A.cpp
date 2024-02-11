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
    std::string s, t;
    std::cin >> n >> s >> t;

    std::string u;
    std::vector<int> rem;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            rem.emplace_back(i);
    }

    if (std::size(rem) % 2)
        std::cout << "-1";
    else if (std::size(rem) == 0)
    {
        u = std::string(n, '0');
        std::cout << u << "\n";
    }
    else
    {
        int ham1 = 0, ham2 = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[i])
                u += '0';
            else if (ham1 * 2 == std::size(rem))
                u += ('1' + '0' - t[i]), ham2++;
            else if (ham2 * 2 == std::size(rem))
                u += ('1' + '0' - s[i]), ham1++;
            else
            {
                if (s[i] == '1')
                    ham1++, u += '0';
                else if (t[i] == '1')
                    ham2++, u += '0';
            }
        }

        assert(std::size(u) == n);
        std::cout << u;
    }

    return 0;
}