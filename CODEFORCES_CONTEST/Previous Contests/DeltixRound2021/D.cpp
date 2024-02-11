#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, p;
    std::cin >> n >> m >> p;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::string ans;
    std::set<int> no;
    for (int i = 0; i < m; ++i)
    {
        int cnt = 0;
        std::vector<int> to_add;

        for (int j = 0; j < n; ++j)
        {
            if (no.count(j))
                continue;

            if (a[j][i] == '0')
                to_add.emplace_back(j);

            cnt += a[j][i] == '1';
        }

        if (cnt >= (n + 1) / 2) 
        {           
            ans += '1';

            for (int i : to_add)
                no.emplace();
        }
        else
            ans += '0';
    }

    std::cout << ans << "\n";
    
    return 0;
}