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
    std::vector<std::vector<T>> mat;
    F func;
    const int n;
 
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

constexpr int inf = 1e9 + 1;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    SparseTable<int> max(a, [&](const int &a, const int &b) { return std::max(a, b); });
    SparseTable<int> min(b, [&](const int &a, const int &b) { return std::min(a, b); });


    std::vector<std::array<int, 2>> pos;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            pos.push_back({b[i], i});
    }

    std::sort(std::begin(pos), std::end(pos));
    for (auto &[_, i] : pos)
    {
        if (max.get(i, i) > b[i])
        {
            std::cout << "NO\n";
            return;
        }

        int left = 0, right = i - 1;
        int ans = i + 1;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            int max_a = max.get(mid, i);
            int min_b = min.get(mid, i);

            if (max_a <= b[i] and min_b >= b[i])
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        left = i + 1, right = n - 1;
        int ansr = i - 1;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            int max_a = max.get(i, mid);
            int min_b = min.get(i, mid); 

            if (max_a <= b[i] and min_b >= b[i])
                ansr = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        int val_left = -inf, val_right = -inf;

        if (ans <= i)
            val_left = max.get(ans, i);
        if (ansr >= i)
            val_right = max.get(i, ansr);

        if (val_left != b[i] and val_right != b[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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