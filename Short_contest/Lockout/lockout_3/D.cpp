#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
class Frac 
{
public:
    T num;
    T den;
    Frac(T num, T den) : num(num), den(den) 
    {
        if (den < 0) 
        {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num) : Frac(num, 1) {}
    double toDouble() const 
    { 
        return 1.0 * num / den; 
    }
    Frac &operator+=(const Frac &rhs) 
    {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) 
    {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) 
    {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) 
    {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) 
    {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) 
    {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) 
    {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) 
    {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac &a) 
    {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac &lhs, const Frac &rhs) 
    {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) 
    {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) 
    {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) 
    {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) 
    {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) 
    {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
};
 
using F = Frac<i64>;

void solve()
{
    int n;
    std::string s;  
    std::cin >> n >> s;

    int d = 0, k = 0;
    std::map<F, int> m;
    for (int i = 0; i < n; i++)
    {
        d += s[i] == 'D';
        k += s[i] == 'K';
        m[F(d, k)]++;
        std::cout << m[F(d, k)] << " \n"[i == n - 1];
    }
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