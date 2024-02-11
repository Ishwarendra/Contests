#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

const int inf = 1e9;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int st = -inf, en = +inf;
    int cnt = 0;

    for (int i = 0; i < n; i++) 
    {
        st = std::max(st, a[i] - x);
        en = std::min(en, a[i] + x);

        if (st > en) {
            cnt++;
            st = a[i] - x, en = a[i] + x;
        }
    }

    std::cout << cnt << "\n";
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