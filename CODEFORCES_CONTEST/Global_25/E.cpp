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

constexpr int P = 1e9 + 7;
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

bool isPalindrome(std::string &s)
{
    int i = 0, j = std::ssize(s) - 1;
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }

    return true;
}

void solve()
{
    const int offset = get_rand(-1000, 1000);
    const int B = get_rand(157, 357);

    std::string s;
    std::cin >> s;

    if (!isPalindrome(s))
    {
        std::cout << "YES\n1\n" << s << "\n";
        return;
    }

    int n = std::size(s);
    auto getHash = [&]()
    {
        std::vector<Z> hash(n);
        Z pw = 1;
        for (int i = 0; i < n; i++)
        {
            hash[i] = (s[i] + offset) * pw;
            if (i > 0)
                hash[i] += hash[i - 1];

            pw *= B;
        }

        return hash;
    };
    
    auto hash = getHash();
    std::reverse(std::begin(s), std::end(s));
    auto rhash = getHash();

    std::vector<Z> pb(n), invpb(n);
    Z pw = 1;
    for (int i = 0; i < n; i++)
    {
        pb[i] = pw;
        invpb[i] = pw.inv();
        pw *= B;
    }

    auto palin = [&](int l, int r)
    {
        Z h = hash[r];
        if (l > 0)
            h -= hash[l - 1];

        h *= invpb[l];

        r = n - r - 1, l = n - l - 1;
        Z rh = rhash[l];
        if (r > 0)
            rh -= rhash[r - 1];

        rh *= invpb[r];
        return h == rh;
    };

    auto work = [&]()
    {
        for (int i = 1; i < n - 2; i++)
        {
            if (palin(0, i) || palin(i + 1, n - 1))
                continue;

            std::cout << "YES\n2\n";
            std::cout << s.substr(0, i + 1) << " " << s.substr(i + 1, n - 1 - i) << "\n";
            return true;
        }

        return false;
    };

    if (!work())
        std::cout << "NO\n";
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