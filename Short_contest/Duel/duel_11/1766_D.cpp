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
        std::vector<int> min_prime(n);
        std::iota(std::begin(min_prime), std::end(min_prime), 0);

        for (int i = 2; i * i < n; i++)
        {   
            if (min_prime[i] == i) for (int j = i * i; j < n; j += i)
                min_prime[j] = std::min(min_prime[j], i);
        }

        return min_prime;
    }

    std::vector<bool> linear_sieve(const int n)
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

        return is_prime;
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

std::vector<int> min_prime;

void solve()
{
    int x, y;
    std::cin >> x >> y;

    if (x > y)
        std::swap(x, y);

    if (y - x == 1)
        std::cout << "-1\n";
    else if (std::gcd(x, y) != 1)
        std::cout << "0\n";
    else if (x % 2 == 1 and y % 2 == 1)
        std::cout << "1\n";
    else
    {
        auto primeFactor = [&](auto d)
        {
            std::vector<int> f;
            while (d != 1)
            {
                f.emplace_back(min_prime[d]);
                d = d / min_prime[d];
            }

            return f;
        };

        int d = y - x;
        auto pf = primeFactor(d);

        int ans = 1e9;
        for (auto num : pf)
            ans = std::min(ans, num - x % num);

        std::cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int N = 1e7 + 1;
    min_prime = nt::sieve(N);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}