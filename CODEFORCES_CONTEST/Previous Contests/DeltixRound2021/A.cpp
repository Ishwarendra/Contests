#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::string s;

    std::cin >> n >> m >> s;

    for (int i = 0; i < m; ++i)  
    {
        int change = 0;
        std::string t = s;

        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1')
                continue;

            int cnt = 0;
            if (j - 1 >= 0)
                cnt += s[j - 1] == '1';
            if (j + 1 < n)
                cnt += s[j + 1] == '1';

            if (cnt == 1)
            {
                t[j] = '1';
                change = 1;
            }
        }

        std::swap(s, t);

        if (!change)
            break;
    }

    std::cout << s << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}