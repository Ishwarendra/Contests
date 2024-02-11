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
    int n, h, m;
    std::cin >> n >> h >> m;

    int t = h * 60 + m;
    int min = 1e9;

    for (int i = 0; i < n; ++i)
    {
        int h1, m1;
        std::cin >> h1 >> m1;

        if (h1 * 60 + m1 >= t)
            min = std::min(min, h1 * 60 + m1 - t);
        else
        {
            min = std::min(min, (23 - h) * 60 + (60 - m) + h1 * 60 + m1);
            print((23 - h) * 60 + (60 - m), h1 * 60 + m1)
        }
    }

    // print(h, m, min)
    h = min / 60;
    m = min % 60;

    std::cout << h << " " << m << "\n";
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