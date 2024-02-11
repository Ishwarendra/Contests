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

        for (int i = 2; i * i < n; i++)
        {
            if (count[i] == 0)
                count[i]++;

            for (int j = i * i; j < n; j += i)
            {
                is_prime[j] = false;
                count[j]++;
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
// std::vector<int> primes;

void solve()
{
    int c, d, x;
    std::cin >> c >> d >> x;

    auto divisors = [&](int a)
    {
        std::vector<int> div;
        for (int i = 1; 1LL * i * i <= a; i++)
        {
            if (a % i == 0)
            {
                div.emplace_back(i);
                if (a != i * i)
                    div.emplace_back(a / i);
            }
        }

        return div;
    };

    auto div = divisors(x);
    i64 ans = 0;
    for (auto g : div)
    {
        x /= g;

        i64 power = 0;
        if ((x + d) % c == 0)
        {
            int prod = (x + d) / c;
            // primes dividing prod
            // for (auto x : primes)
            // {
            //     if (x > prod)
            //         break;

            //     if (prod % x == 0)
            //         power++;
            // }

            ans += (1LL << primes_count[prod]);
            print(power, primes_count[prod], prod)
        }

        x *= g;

    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    primes_count = nt::sieve(N);
    print(primes_count[16], nt::sieve(50)[16])

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}