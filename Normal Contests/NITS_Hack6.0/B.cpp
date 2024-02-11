#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 x) 
{
    std::string s;
    bool neg = false;
    if (x < 0)
        neg = true, x = -x;
    if (x == 0)
        s = "0";
    
    while (x)
    {
        s += '0' + x % 10;
        x /= 10;
    }

    if (neg)
        s += '-';
    s = std::string(std::rbegin(s), std::rend(s));
    return os << s;
}

std::istream& operator >> (std::istream &is, i128 &T) 
{
    static char buffer[64];
    is >> buffer; 
    size_t len = strlen(buffer), index = 0; 
    T = 0; 
    int mul = 1;

    if (buffer[index] == '-') 
        ++index, mul *= -1; 
    for (; index < len; ++index) 
        T = T * 10 + static_cast<int>(buffer[index] - '0'); 
    T *= mul; 

    return is;
}

using i64 = i128;

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

constexpr i64 inf = (long long)(1e18);

i64 get(std::vector<i64> &wt, std::vector<i64> &val, int w)
{
    int n = std::size(wt);
    std::vector<i64> dp(w + 1, -inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector<i64> ndp(w + 1, -inf);
        for (int j = 0; j <= w; j++)
        {
            ndp[j] = std::max(ndp[j], dp[j]);
            if (j - wt[i] >= 0)
                ndp[j] = std::max(ndp[j], dp[j - wt[i]] + val[i]);
        }

        std::swap(dp, ndp);
    }

    return *std::max_element(std::begin(dp), std::end(dp));
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> t(n);
    std::map<int, int> id;
    for (int i = 0; i < n; i++)
    {
        std::cin >> t[i];
        id[t[i]] = 0;
    }

    for (int i = 0; auto &[num, f] : id)
        f = i++;
    // compression done

    std::vector<i64> val(n);
    for (int i = 0; i < n; i++)
        std::cin >> val[i];

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
    }

    std::vector<i64> wt(n, (long long)(1e15));
    Fenwick<i64> ft(n + 1);

    auto dfs = [&](auto &&self, int u, i64 inversion) -> void
    {
        wt[u] = inversion;
        ft.add(id[t[u]], 1);
        for (auto v : adj[u])
            self(self, v, inversion + ft.rangeSum(id[t[v]] + 1, n));

        ft.add(id[t[u]], -1);
    }; dfs(dfs, 0, 0);

    // for (int i = 0; i < n; i++)
    //     std::cout << wt[i] << " \n"[i == n - 1];

    std::cout << get(wt, val, k) << "\n";
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