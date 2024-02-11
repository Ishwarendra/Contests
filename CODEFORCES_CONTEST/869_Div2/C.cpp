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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Fenwick<int> ft(n);
    std::vector<int> b(n);
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] >= a[i + 1] and a[i + 1] >= a[i + 2])
            ft.add(i, 1), b[i]++;
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        
        if (!ft.rangeSum(l, std::max(l, r - 2)))
            std::cout << r - l + 1 << "\n";
        else
            std::cout << std::max(std::min(r - l + 1, 2), r - l + 1 - ft.rangeSum(l, std::max(l, r - 2))) << "\n";
    }
    
    return 0;
}