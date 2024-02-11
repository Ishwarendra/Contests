#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;
 
    SparseTable(const std::vector<T>& a, const F& f) : n(std::size(a)), func(f)
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
 
        }
    }
 
    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::vector<int>> pos(n);

    for (int i = 0; i < n; i++)
        pos[i].emplace_back(-1);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        pos[a[i]].emplace_back(i);
    }

    for (int i = 0; i < n; i++)
        pos[i].emplace_back(n);

    if (std::count(std::begin(a), std::end(a), 0) != 1)
    {
        std::cout << "NO\n";
        return;
    }

    SparseTable<int> min(a, [&](int x, int y) { return std::min(x, y); });
    auto f = [&](auto &&self, int L, int R, int h) -> int
    {
        if (L > R)
            return 1;

        if (min.get(L, R) != h)
            return 0;

        int ans = 1;
        int st = std::lower_bound(std::begin(pos[h]), std::end(pos[h]), L) - std::begin(pos[h]);
        for (int i = st; i < std::size(pos[h]); i++)
        {
            int l = std::max(L, pos[h][i - 1] + 1);
            int r = std::min(R, pos[h][i] - 1);
            ans &= self(self, l, r, h + 1);

            if (pos[h][i] > R)
                break;
        }

        return ans;
    };

    std::cout << (f(f, 0, n - 1, 0) ? "YES\n" : "NO\n");
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