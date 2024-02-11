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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), pos;
    Fenwick<int> ft(m + 1);
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];

        if (a[i] > 0)
            pos.emplace_back(i);

        if (a[i] > 0 and ft.rangeSum(a[i], a[i]) == 0)
            ft.add(a[i], 1);
        else if (a[i] == -1)
            start++;
        else if (a[i] == -2)
            end++;
    }

    int ans = std::min(m, std::max(ft.rangeSum(0, m) + start, ft.rangeSum(0, m) + end));

    for (auto id : pos)
    {
        int cur_ans = 1;
        int start1 = ft.rangeSum(0, a[id] - 1);
        int end1 = ft.rangeSum(a[id] + 1, m);

        cur_ans += std::min(a[id] - 1, start1 + start);
        cur_ans += std::min(m - a[id], end1 + end);
        cur_ans = std::min(m, cur_ans);
        ans = std::max(ans, cur_ans);
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