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
    std::cin >> n >> m;

    std::vector<std::string> s(n), t(m);

    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    for (int i = 0; i < m; i++)
        std::cin >> t[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i].substr(3) == t[j])
            {
                cnt++;
                break;
            }
        }
    }

    std::cout << cnt;

    return 0;
}