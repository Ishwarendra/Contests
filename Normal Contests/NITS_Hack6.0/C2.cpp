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

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

constexpr int B = 317;

std::vector<Z> invB;

void solve()
{
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;

    std::vector<Z> hash(n);
    const int offset = (rng() * rng()) % P;
    hash[0] = s[0] + offset;
    Z mul = B;

    for (int i = 1; i < n; i++)
    {
        int x = s[i] + offset;
        hash[i] = hash[i - 1] + x * mul;
        mul *= B;
    }

    auto where = [&](int l1, int r1, int l2, int r2)
    {
        // 0 -> disjoint, 1 -> inside, 2 -> intersect
        if (l2 > r1 || l1 > r2)
            return 0;

        if (l1 <= l2 and r2 <= r1)
            return 1;
        if (l2 <= l1 and r1 <= r2)
            return 1;

        return 2;
    };

    auto get = [&](int l1, int r1, int l2, int r2)
    {
        auto type = where(l1, r1, l2, r2);
        if (type == 1)
            return std::abs(l2 - l1) * 2 + std::abs(r2 - r1);
        else if (type == 2)
            return std::abs(l2 - l1) * 2 + std::abs(r2 - r1);

        if (r1 < l2)
            return std::abs(r2 - r1) + std::abs(l2 - l1) * 2;

        return std::abs(l2 - l1) * 2 + std::abs(r2 - r1);
    };

    auto getHash = [&](int l, int r)
    {
        if (l == 0)
            return hash[r];
        return (hash[r] - hash[l - 1]) * invB[l];
    };

    while (q--)  
    {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        l1--, l2--, r1--, r2--;

        int sz1 = r1 - l1 + 1;
        int sz2 = r2 - l2 + 1;

        int ans = 10 * n;
        std::vector<std::pair<int, int>> posu, posv;
        for (int i = 0; i < n; i++)
        {
            if (i + sz1 <= n)
            {
                if (getHash(i, i + sz1 - 1) == getHash(l1, r1))
                    posu.emplace_back(i, i + sz1 - 1);
            }

            if (i + sz2 <= n)
            {
                if (getHash(i, i + sz2 - 1) == getHash(l2, r2))
                    posv.emplace_back(i, i + sz2 - 1);
            }
        }

        for (auto &[x1, y1] : posu)        
        {
            for (auto &[x2, y2] : posv)
                ans = std::min(ans, get(x1, y1, x2, y2));
        }

        std::cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int N = 2e5 + 1;
    invB.resize(N);

    invB[0] = Z(1).inv();
    Z b = B;
    for (int i = 1; i < N; i++, b *= B)
        invB[i] = Z(b).inv(); 

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}