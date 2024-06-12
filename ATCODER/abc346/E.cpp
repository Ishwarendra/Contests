#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick 
{
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) { init(n_); }
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    
    void init(int n_) 
    {
        n = n_;
        a.assign(n, T{});
    }


    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) 
            a[i - 1] = a[i - 1] + v;
    }
    
    T sum(int x) 
    {
        T ans{};
        for (int i = x + 1; i > 0; i -= i & -i) 
            ans = ans + a[i - 1];
        return ans;
    }
    
    T rangeSum(int l, int r) 
    { 
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1); 
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector qry(q, std::array<int, 3>());
    std::map<int, i64> ans;

    for (auto &[t, a, c] : qry)
        std::cin >> t >> a >> c;

    std::reverse(std::begin(qry), std::end(qry));

    Fenwick<int> row(n + 1), col(m + 1);

    for (auto &[t, a, c] : qry)
    {
        if (t == 1)
        {
            if (row.rangeSum(a, a))
                continue;

            int cnt = col.sum(m);
            if (m != cnt)
                ans[c] += m - cnt;
            row.add(a, 1);
        }
        else
        {
            if (col.rangeSum(a, a))
                continue;

            int cnt = row.sum(n);
            if (n != cnt)
                ans[c] += n - cnt;
            col.add(a, 1);
        }
    }

    ans[0] = 1LL * n * m;
    for (auto &[c, f] : ans)
    {
        if (c != 0)
            ans[0] -= f;
    }

    if (ans[0] == 0)
        ans.erase(0);

    std::cout << std::size(ans) << "\n";
    for (auto &[c, f] : ans)
    {
        assert(f != 0);
        std::cout << c << " " << f << "\n";
    }
    
    return 0;
}