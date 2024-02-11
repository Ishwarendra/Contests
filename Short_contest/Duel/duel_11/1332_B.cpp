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
        std::vector<int> minp(n);
        std::iota(std::begin(minp), std::end(minp), 0);

        for (int i = 2; i * i < n; i++)
        {
            if (minp[i] == i) for (int j = i * i; j < n; j += i)
                minp[j] = std::min(minp[j], i);
        }

        return minp;
    }

    std::vector<int> linear_sieve(const int n)
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

std::vector<int> prime, min_prime;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> ans(n);
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x = min_prime[a[i]];
        m[x] = 0;
    }

    int id = 0;
    for (auto [num, f] : m)
        m[num] = id++;

    std::cout << std::size(m) << "\n";
    for (int i = 0; i < n; i++)
        std::cout << m[min_prime[a[i]]] + 1 << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int N = std::sqrt(1001) + 1;
    prime = nt::linear_sieve(N);
    min_prime = nt::sieve(1001);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}