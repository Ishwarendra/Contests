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

i64 getInversion(std::vector<int> &a)
{
    int n = std::size(a);
    int max = *std::max_element(std::begin(a), std::end(a));
    Fenwick<int> ft(max + 2);
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += ft.rangeSum(a[i] + 1, max + 1);
        ft.add(a[i], 1);
    }
    
    return ans;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        m[a[i]] = 0;
    }

    int index = 1;
    for (auto &[num, f] : m)
    {
        f = index;
        index += 2;
    }

    for (int i = 0; i < n; i++)
        a[i] = m[a[i]];

    for (int i = 0; i < n; i++)
    {
        i64 max = 0;
        for (int x = 0; x <= index; x++)
        {
            auto old = a[i];
            a[i] = x;
            max = std::max(max, getInversion(a));
            a[i] = old;
        }

        std::cout << max << " \n"[i == n - 1];
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