#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) { init(n); }
    
    void init(int n) 
    {
        this->n = n;
        a.assign(n, T());
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
    
    T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }
    
    int kth(T k) 
    {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) 
        {
            if (x + i <= n && k >= a[x + i - 1]) 
                x += i, k -= a[x - 1];
        }
        return x;
    }
};

constexpr int inf = 1e9;

struct Max
{
    int x;
    Max(int x = -inf) : x(x) {}

    Max &operator+=(Max &a)
    {
        x = std::max(x, a.x);
        return *this;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> pref(n + 1);
    std::map<i64, int> m;

    pref[0] = 0;
    m[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
        m[pref[i]] = 0;
    }

    for (int id = 0; auto &[num, f] : m)
        f = id++;

    std::vector<Max> p(n + 1);
    for (int i = 0; i <= n; i++)
        p[i] = Max(m[pref[i]]);

    Fenwick<Max> ft(n + 3);
    std::vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
    {
        ft.add(p[i - 1].x, dp[i - 1] - (i - 1));
        print(pref[i], p[i].x, ft.sum(p[i].x).x)
        dp[i] = std::max(dp[i - 1], ft.sum(p[i].x).x + i);
    }

    print(dp)
    std::cout << dp.back();

    return 0;
}