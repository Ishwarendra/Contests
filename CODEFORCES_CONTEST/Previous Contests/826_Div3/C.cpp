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
        for (int i = 0; i < n; i++)  
            std::cin >> a[i];

        auto f = [&](int st)
        {
            i64 s = std::accumulate(std::begin(a), std::begin(a) + st, 0LL);
            i64 cur_sum = 0;
            int prev = st;
            int seg = st;

            while (st < n)
            {
                cur_sum += a[st++];
                if (cur_sum == s)
                    seg = std::max(seg, st - prev), prev = st, cur_sum = 0;
                else if (cur_sum > s)
                {
                    seg = n;
                    break;
                }
            }

            if (cur_sum != s and cur_sum != 0)
                seg = n;

            return seg;
        };

        int ans = n;
        for (int i = 0; i < n - 1; i++)
            ans = std::min(ans, f(i + 1));

        std::cout << ans << "\n";

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