#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> pos[51];
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }

    std::string s;
    std::cin >> s;

    for (int i = 0; i < 51; i++)
    {
        if (pos[i].empty())
            continue;

        auto num = pos[i][0];
        char ch = s[num];

        for (int j : pos[i])
        {
            if (ch != s[j])
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
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