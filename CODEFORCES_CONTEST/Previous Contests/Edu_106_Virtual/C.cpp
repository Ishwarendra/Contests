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

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
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

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick(int n) : n(n), a(n) {}
    template<typename G>
    Fenwick(const std::vector<G> in) : Fenwick((int)std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)  
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T get(int l, int r) 
    {
        if (l - 1 < 0)
            return sum(r);
        
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> odd, even;
    for (int i = 0; i < n; i++)  
    {
        i64 x;
        std::cin >> x;

        (i % 2 == 0 ? odd : even).emplace_back(x);
    }

    i64 ans = 1e18;
    SparseTable<i64> odd_min(odd, [&](i64 x, i64 y) { return std::min(x, y); });
    SparseTable<i64> even_min(even, [&](i64 x, i64 y) { return std::min(x, y); });

    Fenwick<i64> odd_sum(odd);
    Fenwick<i64> even_sum(even);

    for (int steps = 2; steps <= n; steps++)
    {
        // RURURURURU
        int R_moves = (steps + 1) / 2;
        int U_moves = steps / 2;

        i64 cur_ans = odd_sum.get(0, R_moves - 1) + odd_min.get(0, R_moves - 1) * 1LL * (n - R_moves);
        print(steps, cur_ans, R_moves, odd_sum.get(0, R_moves - 1), odd)
        cur_ans += even_sum.get(0, U_moves - 1) + 1LL * even_min.get(0, U_moves - 1) * (n - U_moves);

        ans = std::min(ans, cur_ans);
    }

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