#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int>
T get_rand(T l, T r)
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

std::vector<int> factors(int x)
{
    std::vector<int> f;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (x / i >= 3)
                f.emplace_back(x / i);
            if (i != x / i and i >= 3)
                f.emplace_back(i);
        }
    }

    f.emplace_back(x);
    return f;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::sort(std::begin(a), std::end(a));

    while (1. * clock() < CLOCKS_PER_SEC * 1.8)
    {
        int i, j;
        do
        {
            i = get_rand<int>(0, n - 1), j = get_rand(0, n - 1);
        } while (i == j);

        int m = std::abs(a[i] - a[j]);
        if (m <= 2)
            continue;

        for (auto x : factors(m))
        {
            int bal = 0, mod = a[i] % x;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % x == mod)
                    bal++;
                else
                    bal--;
            }

            if (bal > 0)
            {
                std::cout << x << "\n";
                std::exit(0);
            }
        }
    }

    std::cout << "-1\n";

    return 0;
}