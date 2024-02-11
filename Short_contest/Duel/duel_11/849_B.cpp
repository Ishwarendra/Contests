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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    // std::vector pair(n, std::vector(n, 1));
    // for (int i = 0; i < n; i++)
    //     pair[i][i] = 0;

    auto good = [&](int x, int y)
    {
        std::vector<int> one(n);
        one[x] = one[y] = 1;
        F slope(a[y] - a[x], y - x);

        for (int i = 0; i < n; i++)
        {
            if (one[i])
                continue;

            if (slope == F(a[i] - a[x], i - x))
                one[i] = 1;
        }

        // for (int i = 0; i < n; i++)
        // {
        //     if (one[i])
        //         pair[x][i] = 0, pair[i][x] = 0;
        // }

        x = -1, y = -1;
        for (int i = 0; i < n; i++)
        {
            if (one[i] == 0 and x == -1)
                x = i, one[x] = 1;
            else if (one[i] == 0 and y == -1)
                y = i, one[y] = 1;
        }

        if (x == -1 and y == -1)
            return false;
        else if (x == -1 or y == -1)
            return std::count(std::begin(one), std::end(one), 0) == 0;
        else if (slope != F(a[x] - a[y], x - y))
            return false;

        for (int i = 0; i < n; i++)
        {
            if (i == x or i == y)
                continue;

            if (!one[i] and slope != F(a[i] - a[x], i - x))
                return false;

            one[i] = 1;
        }

        return std::count(std::begin(one), std::end(one), 0) == 0;
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (good(i, j))
            {
                std::cout << "Yes\n";
                std::exit(0);
            }
        }
    }

    std::cout << "No\n";
    
    return 0;
}