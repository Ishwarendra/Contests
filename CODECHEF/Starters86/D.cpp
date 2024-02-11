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
        std::vector<int> minP(n);
        std::iota(std::begin(minP), std::end(minP), 0);

        for (int i = 2; i * i < n; i++)
        {
            if (minP[i] == i) for (int j = i * i; j < n; j += i)
                minP[j] = std::min(minP[j], i);
        }

        return minP;
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

constexpr int N = 1e6 + 1;
std::vector<int> prime, min_prime;

std::vector<int> primeFactor(int x)
{
    std::vector<int> pf;
    while (x > 1)
        pf.emplace_back(min_prime[x]), x /= min_prime[x];

    return pf;
};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int g = 0;
    for (int i = 0; i < n; i++)
        g = std::gcd(g, a[i]);

    std::sort(std::begin(a), std::end(a));
    a.erase(std::unique(std::begin(a), std::end(a)), std::end(a));
    n = std::size(a);

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = std::lower_bound(std::begin(prime), std::end(prime), a[i]) - std::begin(prime);

    if (std::size(std::set(std::begin(a), std::end(a))) == 1)
        std::cout << "0\n";
    else if (g > 1)
        std::cout << "1\n" << g << "\n";
    else
    {
        std::set<int> pf;
        for (int i = 0; i < n; i++)
        {
            std::vector<int> temp = primeFactor(a[i]);
            for (auto x : temp)
                pf.emplace(x);
        }

        int max = *(--std::end(pf));
        for (int i = 0; i < std::size(prime); i++)
        {
            if (prime[i] > max)
                break;

            if (!pf.count(prime[i]))
            {
                std::cout << "1\n" << prime[i] << "\n";
                return;
            }
        }

        int big = std::upper_bound(std::begin(prime), std::end(prime), max) - std::begin(prime);

        if (big >= std::size(prime) || prime[big] > m)
            std::cout << "2\n2 3\n";
        else
            std::cout << "1\n" << prime[big] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    prime = nt::linear_sieve(N);
    min_prime = nt::sieve(N);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}