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
    explicit operator double() const { return 1. * num / den; }
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
        if (den < 0) 
        {
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
    friend std::ostream &operator<<(std::ostream &os, const Frac x) 
    {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) 
            return os << x.num / g;
        else 
            return os << x.num / g << "/" << x.den / g;
    }
};
 
using F = Frac<i64>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::pair<F, int>> c;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        c.push_back({F(a, a + b), - i - 1});
    }
    std::sort(std::begin(c), std::end(c), std::greater());
    for (auto &[_, ind] : c)
        std::cout << -ind << " ";
    
    return 0;
}