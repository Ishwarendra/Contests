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

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    std::vector<SparseTable<int>> row, col;

    for (int i = 0; i < n; i++)
        row.push_back(SparseTable<int>(a[i], [&](auto x, auto y) {return std::min(x, y);}));

    for (int i = 0; i < m; i++)
    {
        std::vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.emplace_back(a[j][i]);

        col.push_back(SparseTable<int>(temp, [&](auto x, auto y) {return std::min(x, y);}));
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int min = a[i][j];
            int max_possible = std::min(n - i, m - j);
            if (ans > max_possible)
                continue;
            
            for (int len = 2; len <= std::min(n, m); len++)
            {
                if (i + len - 1 >= n or j + len - 1 >= m)
                    break;

                // (i + len - 1) row and (j + len - 1) column
                min = std::min(min, row[i + len - 1].get(j, j + len - 1));
                min = std::min(min, col[j + len - 1].get(i, i + len - 1));
                if (min < len)
                    break;
                else
                    ans = std::max(ans, len);
            }
        }
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