#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

namespace nt
{
std::vector<bool> sieve(const int n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        for (int j = i * i; j < n; j += i)
            is_prime[j] = false;
    }

    return is_prime;
}

std::vector<int> linearSieve(const int n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;

    std::vector<int> prime;

    for (int i = 2; i < n; i++)
    {
        if (is_prime[i])
            prime.emplace_back(i);

        for (int j = 0; j < std::size(prime) and i * prime[j] < n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;

        }
    }

    return prime;
}

std::vector<int> minPrime(const int n)
{
    std::vector<int> min_prime(n);
    std::iota(std::begin(min_prime), std::end(min_prime), 0);

    for (int i = 2; i * i < n; i++)
    {
        if (min_prime[i] != i)
            continue;
        for (int j = i * i; j < n; j += i)
            min_prime[j] = std::min(min_prime[j], i);
    }

    return min_prime;
}

std::vector<int> phiUptoN(const int n)
{
    std::vector<int> phi(n), prime;
    phi[1] = 1;

    std::vector<bool> is_prime(n, true);

    for (int i = 2; i < n; i++)
    {
        if (is_prime[i])
        {
            phi[i] = i - 1;
            prime.emplace_back(i);
        }

        for (int j = 0; j < std::size(prime) and 1LL * i * prime[j] < n; j++)
        {
            is_prime[i * prime[j]] = false;

            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
        }
    }

    return phi;
}

template<class T>
T phi(T x)
{
    assert(x > 0);
    T res = 1;
    for (T i = 2; i * i <= x; i++)
    {
        if (x % i)
            continue;

        T cur = 1;
        while (x % i == 0)
            x /= i, cur *= i;
        res *= (cur - cur / i);
    }

    if (x > 1)
        res *= (x - 1);
    return res;
}
};

constexpr int N = 1e6 + 1;
std::vector<int> prime;

void solve()
{
    int l, r;
    std::cin >> l >> r;

    auto between = [&](int x, int l, int r)
    {
        return l <= x and x <= r;
    };

    for (int g : prime)
    {   
        int L = (l + g - 1) / g;
        int R = r / g;

        int a = 1, b = R - 1;
        if (between(a + b, L, R) and a > 0 and b > 0)
        {
            std::cout << g * a << " " << g * b << "\n";
            return;
        }
    }

    std::cout << "-1\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    prime = nt::linearSieve(N);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}