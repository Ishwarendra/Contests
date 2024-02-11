#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 a, b, c;
    std::cin >> a >> b >> c;

    auto get = [&](int op)
    {
        int n = 3 + op;
        if ((a + b + c) % n)
            return false;

        int need = (a + b + c) / n;
        int cnt = 0;

        for (auto x : {a, b, c})
        {
            if (x % need)
                return false;
            cnt += x / need - 1;
        }

        return cnt <= 3;
    };

    for (int i = 0; i < 4; i++)
    {
        if (get(i))
        {
            std::cout << "YES\n";
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