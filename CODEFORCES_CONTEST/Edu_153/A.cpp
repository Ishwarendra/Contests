#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    auto check = [&](std::string t)
    {
        for (int i = 0; i < n; i++)
        {
            if (t.substr(i, n) == s)
                return false;
        }

        return true;
    };

    std::string t1, t2;
    for (int i = 0; i < n; i++)
        t1 += "()";

    for (int i = 0; i < n * 2; i++)
        t2 += (i < n ? '(' : ')');

    for (auto t : {t1, t2})
    {
        if (check(t))
        {
            std::cout << "YES\n" << t << "\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}