#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DS 
{
    int LIMIT;
    std::multiset<int> m;
    i64 sum = 0;
    DS(int LIMIT) : LIMIT(LIMIT) {}
    void add(int x)
    {
        if (x < 0)
            return;

        if (std::size(m) < LIMIT)
            m.emplace(x), sum += x;
        else
        {
            if (x > *std::begin(m))
            {
                sum -= *std::begin(m);
                sum += x;
                m.erase(std::begin(m)), m.emplace(x);
            }
        }
    }

    i64 get() { return sum; }
};

void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 ans = 0;
    i64 max_sum = 0;
    DS ds(m);

    for (int i = 0; i < n; i++)
    {
        ds.add(a[i]);
        auto cur = ds.get();
        cur -= 1LL * (i + 1) * d;
        ans = std::max(ans, cur);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    std::cerr << "Time elapsed: " << 1000. * clock() / CLOCKS_PER_SEC << " ms.\n";

    return 0;
}