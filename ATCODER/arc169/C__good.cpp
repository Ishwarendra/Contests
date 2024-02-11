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

    int ans = 0;
    std::function<void(int)> f;
    f = [&](int id)
    {
        if (id == n)
        {
            std::map<int, int> m;
            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                m[a[i]]++;
                if (m[a[i]] > a[i])
                    ok = 0;
            }

            if (ok)
                print(a)
            ans += ok;
            return;
        }

        if (a[id] == -1)
        for (int x = 1; x <= n; x++)
        {
            a[id] = x;
            f(id + 1);
            a[id] = -1;
        }
        else f(id + 1);
    }; f(0);

    std::cout << ans;
    return 0;
}