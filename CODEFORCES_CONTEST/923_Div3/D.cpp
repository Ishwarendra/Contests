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
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        pos[a[i]].emplace_back(i + 1);
    }

    SparseTable<int> min_st(a, [&](int x, int y) { return std::min(x, y); });
    SparseTable<int> max_st(a, [&](int x, int y) { return std::max(x, y); });

    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        
        int min = min_st.get(l - 1, r - 1);
        int max = max_st.get(l - 1, r - 1);

        if (min == max)
            std::cout << "-1 -1\n";
        else
        {
            int id_min = *std::lower_bound(std::begin(pos[min]), std::end(pos[min]), l);
            int id_max = *std::lower_bound(std::begin(pos[max]), std::end(pos[max]), l);

            std::cout << id_min << " " << id_max << "\n";
        }
    }
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