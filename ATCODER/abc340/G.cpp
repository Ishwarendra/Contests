#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
}

template<class T>
T inverse(T a, T m) 
{
    T u = 0, v = 1;
    while (a != 0) 
    {
        T t = m / a;
        m -= t * a; 
        u -= t * v; 
        std::swap(a, m);
        std::swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        if (P > 0) 
            return P;
        else 
            return Mod;
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const 
    {
        if (x < 0) 
            x += getMod();
        
        if (x >= getMod()) 
            x -= getMod();
        
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const 
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> col(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        c--;

        col[c].emplace_back(i);
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    const int m = std::__lg(n) + 2;
    std::vector dp(n, std::vector(m, 0));
    std::vector tout(n, 0), tin(n, 0);
    int dfs_time = 0;

    auto dfs1 = [&](auto &&self, int u, int p) -> void
    {
        tin[u] = dfs_time++;
        dp[u][0] = p;
        for (int v : adj[u])
        {
            if (v != p)
                self(self, v, u);
        }
        tout[u] = dfs_time;
    }; dfs1(dfs1, 0, 0);

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }

    auto isAncestor = [&](int u, int v)
    {
        return tin[u] <= tin[v] and tout[v] <= tout[u];
    };

    auto lca = [&](int u, int v)
    {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;

        for (int i = m - 1; i >= 0; i--)
        {
            if (!isAncestor(dp[u][i], v))
                u = dp[u][i];
        }

        return dp[u][0];
    };

    auto cmp = [&](int u, int v) { return tin[u] < tin[v]; };

    Z ans = 0;
    for (int c = 0; c < n; c++)
    {
        if (col[c].empty())
            continue;

        std::vector<int> nodes;
        for (int u : col[c])
            nodes.emplace_back(u);

        std::sort(std::begin(nodes), std::end(nodes), cmp);
        int sz = std::size(nodes);
        for (int i = 1; i < sz; i++)
            nodes.emplace_back(lca(nodes[i], nodes[i - 1]));

        std::sort(std::begin(nodes), std::end(nodes), cmp);
        nodes.erase(std::unique(std::begin(nodes), std::end(nodes)), std::end(nodes));

        std::stack<int> st;
        std::map<int, std::vector<int>> g;
        
        for (int i = 0; i < std::size(nodes); i++)
        {
            while (std::size(st) > 1 and !isAncestor(st.top(), nodes[i]))
            {
                int f = st.top();
                st.pop();
                g[st.top()].emplace_back(f);
                g[f].emplace_back(st.top());
            }

            st.emplace(nodes[i]);
        }

        while (std::size(st) > 1)
        {
            int f = st.top();
            st.pop();
            g[st.top()].emplace_back(f);
            g[f].emplace_back(st.top());
        }

        auto dfs2 = [&](auto &&self, int u, int p) -> Z
        {
            Z sum = 0, prod = 1;
            for (int v : g[u])
            {
                if (v == p)
                    continue;

                auto value = self(self, v, u);
                sum += value;
                prod *= (1 + value);
            }

            if (std::binary_search(std::begin(col[c]), std::end(col[c]), u))
                ans += prod;
            else
            {
                prod -= 1;
                ans += prod - sum;
            }

            return prod;
        }; dfs2(dfs2, nodes[0], nodes[0]);
    }
    
    std::cout << ans;

    return 0;
}