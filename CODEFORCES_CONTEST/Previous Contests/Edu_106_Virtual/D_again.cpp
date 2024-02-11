#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

namespace nt
{
std::vector<int> sieve(const int n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;

    std::vector<int> count(n);

    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
            continue;

        for (int j = i; j < n; j += i)
        {
            count[j] += 1;
            if (j != i)
                is_prime[j] = false;
        }
    }

    return count;
}

    std::vector<int> linear_sieve(const int n)
    {
        std::vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;

        std::vector<int> prime;
        std::vector<int> count(n);

        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                count[i] = 1;
                prime.emplace_back(i);
            }

            for (int j = 0; j < std::size(prime) and i * prime[j] < n; j++)
            {
                is_prime[i * prime[j]] = false;

                if (i % prime[j] == 0)
                {
                    count[i * prime[j]] += count[i];
                    break;
                }

                count[i * prime[j]] += 1 + count[i];
            }
        }

        return count;
    }

    std::vector<int> phi_upton(const int n)
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

constexpr int N = 2e7 + 10;
std::vector<int> primes_count;

void solve()
{
    int c, d, x;
    std::cin >> c >> d >> x;

    i64 ans = 0;
    
    auto f = [&](int g)
    {
        x /= g;

        if ((x + d) % c == 0)
        {
            int prod = (x + d) / c;
            ans += (1LL << primes_count[prod]);
        }

        x *= g;
    };

    for (int i = 1; 1LL * i * i <= x; i++)
    {
        if (x % i == 0)
        {
            f(i);
            if (i * i != x)
                f(x / i);
        }
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    primes_count = nt::sieve(N);
    
    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}