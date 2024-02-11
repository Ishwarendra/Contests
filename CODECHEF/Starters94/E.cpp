#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick() {}
    Fenwick(int n) : n(n), a(n, T()) {}
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
    
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) 
            a[i - 1] += v;
    }
    
    T sum(int x) 
    {
        auto ans = T();
        for (int i = x + 1; i > 0; i -= i & -i) 
            ans += a[i - 1];
        return ans;
    }
    
    T rangeSum(int l, int r) 
    { 
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1); 
    }
};

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    std::map<int, int> id;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        id[a[i]] = 0;
    }

    int pos = 1;
    for (auto &[num, f] : id)
        f = pos++;

    Fenwick<int> ft(pos + 2);
    std::vector<int> pref(n), suff(n);
    for (int i = 0; i < n; i++)
    {
        pref[i] += ft.rangeSum(id[a[i]] + 1, ft.n - 1);
        ft.add(id[a[i]], 1);
    }

    std::fill(std::begin(ft.a), std::end(ft.a), 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] += ft.rangeSum(id[a[i]] + 1, ft.n - 1);
        ft.add(id[a[i]], 1);
    }

    while (q--)
    {
        int k, r;
        std::cin >> k >> r;
        k--;

        int x = id[a[k]];
        int rnk = ft.rangeSum(x + 1, ft.n - 1) + 1;

        if (rnk <= r)
            std::cout << "0\n";
        else
        {
            int left = pref[k];
            int right = suff[k];

            int need = rnk - r;
            if (left >= (need + 1) / 2 and right >= (need + 1) / 2)
                std::cout << (need + 1) / 2 << "\n";
            else
                std::cout << need - std::min(left, right) << "\n";
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