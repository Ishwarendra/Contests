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

    int n = 5;
    int m = 0;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = get_rand<int>(0, 10);

    int sum = std::accumulate(std::begin(a), std::end(a), 0);
    m = get_rand<int>(0, sum);

    std::cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    
    return 0;
}