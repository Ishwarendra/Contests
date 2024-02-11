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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::array<std::vector<int>, 2> c;
    for (int i = 0; i < n; i++)
        c[b[i] - 1].emplace_back(a[i]);

    std::sort(std::begin(c[0]), std::end(c[0]));
    std::sort(std::begin(c[1]), std::end(c[1]));

    std::vector<i64> ft2(std::size(c[1])), ft1(std::size(c[0]));   

    if (!c[1].empty())
        ft2[0] = c[1][0];
    if (!c[0].empty())
        ft1[0] = c[0][0];

    for (int i = 1; i < std::ssize(c[0]); i++)
        ft1[i] = ft1[i - 1] + c[0][i];

    for (int i = 1; i < std::ssize(c[1]); i++)
        ft2[i] = ft2[i - 1] + c[1][i];

    int ans = 1e9;
    int id = std::lower_bound(std::begin(ft2), std::end(ft2), m) - std::begin(ft2);

    if (id != std::ssize(ft2))
        ans = (id + 1) * 2;

    for (int i = 0; i < std::ssize(c[0]); i++)
    {   
        i64 sum = ft1[i];
        int cur_ans = i + 1;

        if (sum >= m)
        {
            ans = std::min(ans, cur_ans);
            continue;
        }

        id = std::lower_bound(std::begin(ft2), std::end(ft2), m - sum) - std::begin(ft2);
        if (id != std::ssize(ft2))
            cur_ans += (id + 1) * 2;

        ans = std::min(ans, cur_ans);
    }

    std::cout << (ans == 1e9 ? 1 : ans) << "\n";
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