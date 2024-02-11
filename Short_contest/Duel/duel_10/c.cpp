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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::multiset m(std::begin(b), std::end(b));
    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        int need = n - a[i];
        need %= n;
        auto it = m.lower_bound(need);
        if (it == std::end(m))
            it--;

        int f = *it, s = *std::begin(m);

        if ((f + a[i]) % n < (s + a[i]) % n)
            c[i] = f, m.erase(it);
        else
            c[i] = s, m.erase(std::begin(m));
    }

    for (int i = 0; i < n; i++)
        std::cout << (c[i] + a[i]) % n << " \n"[i == n - 1];
    
    return 0;
}