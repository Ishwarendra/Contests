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

void solve()
{
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    auto b = a;
    std::sort(std::begin(b), std::end(b));
    for (int i = 0; i < n; i++)
        pos[b[i]].emplace_back(i);
    
    std::vector<i64> ans(n);
    Fenwick<i64> sum(n), nonzero(n);
    
    auto get = [&](int need)
    {
        int left = 0, right = n - 1;
        int ans = -1;
        
        while (left <= right)  
        {
            int mid = (left + right) / 2;
            if (nonzero.sum(mid) <= need)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        
        return ans;
    };
    
    for (int i = 0; i < n; i++)
    {
        sum.add(pos[a[i]].back(), a[i]);
        nonzero.add(pos[a[i]].back(), 1);
        pos[a[i]].pop_back();
        
        if (i % 2 == 0)
        {
            int need = i / 2;
            auto j = get(need);
            ans[i] = sum.sum(n - 1) - 2 * sum.sum(j);
        }
    }
   
    while (q--)
    {
        int k;
        std::cin >> k;
        std::cout << ans[k - 1] << " \n"[q == 0];
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