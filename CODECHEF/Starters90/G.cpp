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

constexpr int N = 2e5 + 1;
std::vector<int> min_prime;

void solve()
{
    int n;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << "1\n1 2\n";
        return;
    }

    std::vector<int> ans, extra;
    std::set<int> done;

    for (int i = n; i >= 2; i--)
    {
        if (min_prime[i] != i or done.count(i))
            continue;

        std::vector<int> options;
        for (int k = 1; k * i <= 2 * n; k++)
        {
            if (done.count(k * i))
                continue;
            done.emplace(k * i);
            options.emplace_back(k * i);
        }

        int cnt = std::size(options);
        if (cnt == 1)
            extra.emplace_back(options[0]);
        else if (cnt % 2 == 0)
            ans.insert(std::end(ans), std::begin(options), std::end(options));
        else
        {
            for (auto x : options)
            {
                if (x == 2 * i)
                    extra.emplace_back(x);
                else
                    ans.emplace_back(x);
            }
        }
    }

    int left = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!done.count(i))
            extra.emplace_back(i);
    }

    for (int i = 0; i < std::size(ans); i += 2)
        left += std::gcd(ans[i], ans[i + 1]) == 1;
    for (int i = 0; i < std::size(extra); i += 2)
        left += std::gcd(extra[i], extra[i + 1]) == 1;

    std::cout << left << "\n";
    for (int i = 0; i < std::size(ans); i += 2)
        std::cout << ans[i] << " " << ans[i + 1] << "\n";
    for (int i = 0; i < std::size(extra); i += 2)
        std::cout << extra[i] << " " << extra[i + 1] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    min_prime = nt::minPrime(N);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}