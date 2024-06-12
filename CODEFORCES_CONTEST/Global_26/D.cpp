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

constexpr int P = 1e9 + 9;
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
    const int offset = -get_rand('a', 'a');
    const Z B = get_rand(2, 2);
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector<int> pos, nona;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            pos.emplace_back(i);
        else
            nona.emplace_back(i);
    }

    if (std::size(pos) == n)
    {
        std::cout << n - 1 << "\n";
        return;
    }
    
    std::vector<Z> hash(n), pw(n);
    hash[0] = s[0] + offset;
    Z mul = B;
    pw[0] = 1;
    for (int i = 1; i < n; i++, mul *= B)
    {
        pw[i] = mul;
        hash[i] = hash[i - 1] + mul * (s[i] + offset);
    }
    
    for (int i = 0; i < n; i++)
        std::cout << hash[i] << " \n"[i == n - 1];

    auto getHash = [&](int l, int r)
    {
        Z h = hash[r] - (l ? hash[l - 1] : 0);
        return h / pw[l];
    };
    
    if (n == 4)
        print(getHash(0, 1).x, int(getHash(2, 3) * pw[2]))

    auto get = [&](int st, int len) -> i64
    {
        std::vector<int> back, front;
        for (int i = st, prev = -1; i < n;)
        {
            if (s[i] == 'a')
            {
                front.back()++;
                i++;
                continue;
            }

            if (i + len > n or getHash(st, st + len - 1) != getHash(i, i + len - 1))
                return 0;

            back.emplace_back(std::max(0, i - prev - 1));
            if (front.empty() || front.back() > 0)
                front.emplace_back();

            i += len;
            prev = i - 1;
        }

        int minb = *std::min_element(std::begin(back), std::end(back));
        int minf = *std::min_element(std::begin(front), std::end(front));

        int x = n;
        for (int i = 1; i < std::size(back); i++)
            x = std::min(x, back[i]);

        i64 res = 0;
        for (int f = 0; f <= minf; f++)
        {
            int need = x - f;
            if (need < 0)
                continue;

            need = std::min(need, minb);
            res += need + 1;
        }
        
        return res;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'a')
        {
            for (int len = 1; i + len <= n; len++)
            {
                if (s[i + len - 1] == 'a')
                    continue;
                ans += get(i, len);
            }
            break;
        }
    }
    
    std::cout << ans << "\n";
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