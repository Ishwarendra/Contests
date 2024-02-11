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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << "1\n";
    int n = 6, m = 6;
    std::cout << n << " " << m << "\n";

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    std::shuffle(std::begin(a), std::end(a), rng);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];

    for (int i = 0; i < n; i++)
    {
        if (i == 2 or i == 4)
            std::cout << get_rand(1, m) << " ";
        else
            std::cout << "0 ";
    }
    
    return 0;
}