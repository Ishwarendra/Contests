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

template <typename T>
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
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(i64 x) : x{norm(x % P)} {}

    int norm(int x)
    {
        if (x < 0)
            x += P;
        if (x >= P)
            x -= P;
        return x;
    }
    int val() const { return x; }
    MInt operator-() const
    {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    MInt &operator*=(const MInt &rhs)
    {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) { return *this *= rhs.inv(); }
    friend MInt operator*(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a)
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

std::vector<std::vector<int>> getCycles(std::vector<int> &p)
{
    int n = std::size(p);
    std::vector<std::vector<int>> ans;
    std::vector<int> vis(n);

    for (int i = 0; i < n; i++)
    {
        int u = i;
        std::vector<int> temp;
        while (!vis[u])
        {
            vis[u] = 1;
            temp.emplace_back(u);
            u = p[u];
        }

        if (!temp.empty())
            ans.emplace_back(temp);
    }

    return ans;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n), a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
    }

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto check = [&]()
    {
        std::map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0 and a[p[i]] != 0)
                m[a[p[i]]]++;
        }

        return std::size(m) <= 1;
    };

    Z ans = 1;

    auto cycles = getCycles(p);
    int num = -1;
    for (auto cyc : cycles)
    {
        for (auto id : cyc)
        {
            if (a[id] != 0)
            {
                if (num == -1)
                    num = a[id];
            }
        }
    }

    // print(cycles)
    std::set<int> after;
    for (auto cyc : cycles)
    {
        std::map<int, int> mp, become;
        std::set<int> idx (std::begin(cyc), std::end(cyc));

        for (auto id : idx)
            mp[id] = id;
        for (auto id : idx)
        {
            mp[id] = mp[p[id]];
            after.emplace(a[mp[p[id]]]);
            // print(a[p[id]], id)
        }

        std::set<int> nidx;
        for (auto [_, id] : mp)        
            nidx.emplace(id);

        int sz = int(std::size(cyc)) - int(std::size(nidx));
        for (auto id : idx)
        {
            if (!nidx.count(id) and a[id] != 0)
                sz--;
        }
        ans *= power<Z>(m, sz);
    }

    after.erase(0);
    if (after.empty())
        ans *= m;
    else if (std::size(after) > 1)
        ans = 0;

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