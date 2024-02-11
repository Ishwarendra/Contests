#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

i64 remaining(i64 x)
{
    std::map<i64, int> m;

    while (x % 2 == 0)
        m[2]++, x /= 2;

    for (int i = 3; i * i <= x; i += 2)
    {
        while (x % i == 0)
            m[i]++, x /= i;
    }

    if (x > 1)
        m[x]++;

    i64 rem = 1;

    for (auto p : m)
        if (p.second % 2)
            rem *= p.first;

    return rem;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    i64 ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        i64 rem = remaining(i);

        for (int j = 1;; j++)
        {
            if (j * j * rem > n)
                break;
            else
                ans++;
        }
    }

    std::cout << ans << "\n";

    return 0;
}