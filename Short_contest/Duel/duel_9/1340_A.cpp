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
    T rangeSum(int l, int r) 
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

    std::vector<int> p(n);
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> p[i];
        pos[--p[i]] = i;
    }

    int can = 1;
    
    Fenwick<int> ft(n);
    ft.add(pos[0], 1);

    auto get_suff = [&]()
    {
        int left = 0, right = n - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (ft.rangeSum(mid, n - 1) == n - mid)
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    };

    for (int i = 1; i < n; i++)
    {
        if (n - i == get_suff()); // i can be anywhere        
        else
        {
            if (pos[i] != pos[i - 1] + 1)
                can = 0;
        }

        ft.add(pos[i], 1);
    }

    std::cout << (can ? "Yes\n" : "No\n");
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