#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
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

constexpr int P = 1036726063;
using Z = MInt<P>;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get()
};
std::mt19937_64 rng(seed);

template<class T = int>
T get_rand(T l, T r)
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

void solve()
{
    const int B = get_rand(255, 4657);
    const int zero = rng();
    const int one = rng();

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    auto get = [&](char ch)
    {
        return (ch == '0' ? zero : one);
    };
    std::vector<Z> pw(n + 1, 1);
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * B;
    
    auto getHash = [&](std::string & s)
    {
        int n = std::size(s);
        std::vector<Z> hash(n);
        hash[0] = s[0] == '0' ? zero : one;
        for (int i = 1; i < n; i++)
            hash[i] = hash[i - 1] + pw[i] * get(s[i]);
        return hash;
    };
    
    auto hash = getHash(s);
    std::reverse(std::begin(s), std::end(s));
    auto rhash = getHash(s);
    std::reverse(std::begin(s), std::end(s));

    Z hash0 = 0, hash1 = 0;
    std::string t;
    for (int i = 0; i < n / k; i++)
        t += std::string(k, i % 2 ? '1' : '0');
    hash0 = getHash(t).back();
    
    t.clear();
    for (int i = 0; i < n / k; i++)
        t += std::string(k, i % 2 ? '0' : '1');
    hash1 = getHash(t).back();
    
    auto val = [&](auto &hash, int l, int r)
    {
        return (hash[r] - (l ? hash[l - 1] : 0)) / pw[l];  
    };
    
    auto rval = [&](int l, int r)
    {
        return val(rhash, n - r - 1, n - l - 1);
    };
    
    if (hash0 == hash.back() || hash1 == hash.back())
    {
        std::cout << n << "\n";
        return;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        Z r = rval(0, i);
        Z h = val(hash, i + 1, n - 1);
        h = h + pw[n - 1 - i] * r;
        
        if (h == hash0 || h == hash1)
        {
            std::cout << i + 1 << "\n";
            return;
        }
    }
    
    std::cout << "-1\n";
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