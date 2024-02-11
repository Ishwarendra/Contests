#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (p2 > p1)
                std::swap(p1, p2);

            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto get = [&](int i, int j)
    {
        int ans = 0;
        DSU dsu(n);
        std::vector b(j - i + 1, std::array {0, 0});
        for (int k = i; k <= j; k++)
            b[k - i] = {a[k], k};
        std::sort(std::begin(b), std::end(b));

        for (int k = i; k <= j; k++)
        {
            if (b[k - i][0] != a[k])
                dsu.unite(b[k - i][1], k);
        }

        for (int k = i; k <= j; )
        {
            int max = dsu.get(k) + 1;
            for (int x = k + 1; x < max; x++)
                max = std::max(max, dsu.get(x) + 1);

            ans += max - k - 1;
            k = max;
        }
        return ans;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            print(j, i, get(j, i))
            // ans += get(i, j);
        }
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

    return 0;
}