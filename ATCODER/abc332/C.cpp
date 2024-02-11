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

    int n, m;
    std::string s;
    std::cin >> n >> m >> s;

    int plain = m, logo = 0;
    int logo_used = 0;

    for (auto &ch : s)
    {
        if (ch == '0')
        {
            logo_used = 0;
            plain = m;
        }
        else if (ch == '1')
        {
            if (plain)
                plain--;
            else
            {
                if (logo - logo_used > 0)
                    logo_used++;
                else
                    logo++, logo_used++;
            }
        }
        else
        {
            if (logo - logo_used > 0)
                logo_used++;
            else
                logo++, logo_used++;
        }
    }

    std::cout << logo;

    return 0;
}